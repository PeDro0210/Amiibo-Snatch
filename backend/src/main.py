from flask import Flask, jsonify, send_from_directory,request
from flask_cors import CORS
import os
from dotenv import load_dotenv
import services.endpointsLogic as services

app = Flask(__name__)
CORS(app)

@app.route('/amiibo', methods=['GET'])
def amiibo_route():
    if request.args.get("key") == os.getenv("ACCESS_KEY"):
        return services.amiibo_info() 
    return jsonify({"error":"api key is invalid"})
if __name__ == '__main__':
    app.run(debug=True)
