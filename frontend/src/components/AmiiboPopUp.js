import React from "react";

function AmiiboPopUp( //this is why I rather using static languages
  { image,
    character,
    gameSeries,
    amiiboSeries }
) {



  return (
    <div className="amiibo-popup">
      <img src={image} alt={character} />
      <p>Amiibo Series: {amiiboSeries}</p>
      <p>Character: {character}</p>
      <p>Game Series: {gameSeries}</p>
    </div>

  );
}

export default AmiiboPopUp;
