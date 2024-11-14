// FILE: pages/AmiiboPage.js
import React, { useState, useEffect } from 'react';
import '../styles/AmiiboPage.css';
import '../components/AmiiboPopUp.js'
import AmiiboPopUp from '../components/AmiiboPopUp.js';

function AmiiboPage() {
  const [amiiboData, setAmiiboData] = useState(null);

  useEffect(() => {
    //    const fetchAmiiboData = async () => {
    //      try {
    //        const response = await fetch('http://localhost:5000/amiibo');
    //        const data = await response.json();
    //        setAmiiboData(data);
    //      } catch (error) {
    //        console.error('Error fetching amiibo data:', error);
    //      }
    //    };

    //tries to fetch new info every 3 seconds
    //    setTimeout(fetchAmiiboData, 3000);
  }, []);

  return (
    <div className="amiibo-page">
      <div className="amiibo-background"></div>
      <div className="amiibo-content">
        <img
          src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/amiibo_logo.png/1280px-amiibo_logo.png"
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
