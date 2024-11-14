from flask import jsonify
import services.apiClient as api

def amiibo_info():
    try:
        amiibo_id = api.get_amiibo_id_from_esp32()

        data_api = api.get_data(amiibo_id)["amiibo"]
        
        return jsonify({
            "amiiboSeries": data_api.get("amiiboSeries"),
            "character": data_api.get("character"),
            "gameSeries": data_api.get("gameSeries"),
            "image": data_api.get("image"),
            "status":200
        })
    except:
        return jsonify({"status":"404"}) 

        
