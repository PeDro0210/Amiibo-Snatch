from flask import Flask, jsonify, send_from_directory
from flask_cors import CORS
import services.endpointsLogic as services

app = Flask(__name__)
CORS(app) #TODO: manage the Cors


@app.route('/amiibo', methods=['GET'])
def amiibo_route():
    return services.amiibo_info() 

if __name__ == '__main__':
    app.run(debug=True)
