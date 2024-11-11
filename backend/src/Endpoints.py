
"""
TODO: Add an endpoint which returns
a json with this structure

{
    data:{
        "amiiboSeries",
        //and the rest of the data for the api
    }

}
"""

from flask import Flask, app, jsonify
import requests
from ApiClient import get_data


def get_amiibo_id_from_esp32():
    esp32_url = 'http://esp32/getid' #Depende de que lo enchufe dijo el pegdro
    try:
        response = requests.get(esp32_url)
        response.raise_for_status()
        esp32_data = response.json()
        
        return esp32_data.get("data", None)
    except requests.exceptions.RequestException as e:
        print(f"No se ecnontro Id en ESP32: {e}")
        return None

@app.route('/amiibo', methods=['GET'])
def amiibo_info():

    amiibo_id = get_amiibo_id_from_esp32()
    
    if amiibo_id:
       
        data = get_data(amiibo_id)
        
        
        if 'amiibo' in data and data['amiibo']:
            filtered_data = {
                "amiiboSeries": data['amiibo'][0].get("amiiboSeries"),
                "character": data['amiibo'][0].get("character"),
                "gameSeries": data['amiibo'][0].get("gameSeries"),
                "image": data['amiibo'][0].get("image")
            }
            return jsonify(filtered_data)
        else:
            return jsonify({"error": "Data no ecnotrada"}), 404
    else:
        return jsonify({"error": "No se ecnontro Id en ESP32"}), 500