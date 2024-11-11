"""
TODO: call the api in here

"""

import requests

def get_data(Id):
    url = 'https://www.amiiboapi.com/api/amiibo/?id=' + Id
    try:

        response = requests.get(url)

        
        response.raise_for_status()

        
        return response.json()

    except requests.exceptions.RequestException as e:
        print(f"Error fetching data: {e}")
        return {}
    



# Prueba UWU
item_id = "01010000000e0002"
data = get_data( item_id)

if data:
    print("Funciono:", data)
else:
    print("Womp Womp.")
