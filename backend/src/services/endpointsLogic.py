from flask import jsonify
import apiClient as api

def amiibo_info():

    amiibo_id = api.get_amiibo_id_from_esp32()
    
    if amiibo_id:
       
        data = api.get_data(amiibo_id)
        
        
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
