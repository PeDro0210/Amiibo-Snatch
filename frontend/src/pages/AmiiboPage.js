// FILE: pages/AmiiboPage.js
import React, { useState, useEffect } from 'react';
import '../styles/AmiiboPage.css';
import '../components/AmiiboPopUp.js'
import AmiiboPopUp from '../components/AmiiboPopUp.js';

function AmiiboPage() {
  const [amiiboData, setAmiiboData] = useState(null);

  useEffect(() => {
    const fetchAmiiboData = async () => {
      try {
        const response = await fetch('http://127.0.0.1:5000/amiibo?key=9123jsaasdkf02jfks9gjnk2j23jdk');
        const data = await response.json();

        if (data["status"] == 200) {
          setAmiiboData(data);
        }
      } catch (error) {
        console.error('Error :', error);
      }
    };
    const intervalId = setInterval(fetchAmiiboData, 3000);

    return () => clearInterval(intervalId);
  }, []);

  return (
    <div className="amiibo-page">
      <div className="amiibo-background"></div>
      <div className="amiibo-content">
        <img
          src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/amiibo_logo.png/1280px-amiibo_logo.png"
          crossOrigin='anonymous'
          alt="amiibo"
          className="amiibo-logo"
        />
        <p className="micro-5-regular">Acerca tu personaje al lector</p>

        {amiiboData && (
          <AmiiboPopUp
            image={amiiboData.image}
            character={amiiboData.character}
            gameSeries={amiiboData.gameSeries}
            amiiboSeries={amiiboData.amiiboSeries}
          />
        )}
      </div>
    </div>
  );
}

export default AmiiboPage;
