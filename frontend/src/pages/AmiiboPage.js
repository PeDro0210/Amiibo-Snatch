// FILE: pages/AmiiboPage.js
import React, { useState, useEffect } from 'react';
import './AmiiboPage.css';

function AmiiboPage() {
  const [amiiboData, setAmiiboData] = useState(null);

  useEffect(() => {
    // Simulación de la detección del Amiibo
    const fetchAmiiboData = async () => {
      try {
        const response = await fetch('http://localhost:5000/amiibo');
        const data = await response.json();
        setAmiiboData(data);
      } catch (error) {
        console.error('Error fetching amiibo data:', error);
      }
    };

    // Simular la detección del Amiibo después de 3 segundos
    setTimeout(fetchAmiiboData, 3000);
  }, []);

  return (
    <div className="amiibo-page">
      <div className="amiibo-background">
        {/* Espacio para la imagen de fondo estilo Mario */}
      </div>
      <div className="amiibo-content">
        <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/Amiibo_logo.png/1280px-Amiibo_logo.png" alt="Amiibo" className="amiibo-logo" />
        <p className="micro-5-regular">Acerca tu personaje al lector</p>
        {amiiboData && (
          <div className="amiibo-popup">
            <img src={amiiboData.image} alt={amiiboData.character} />
            <p>Amiibo Series: {amiiboData.amiiboSeries}</p>
            <p>Character: {amiiboData.character}</p>
            <p>Game Series: {amiiboData.gameSeries}</p>
          </div>
        )}
      </div>
    </div>
  );
}

export default AmiiboPage;