"""
TODO: call the api in here

"""
import requests



def get_amiibo_id_from_esp32():
    esp32_url = 'http://192.168.0.43/getid'
    try:
        response = requests.get(esp32_url)
        response.raise_for_status()
        esp32_data = response.json()
        
        return esp32_data.get("data", None)
    except requests.exceptions.RequestException as e:
        print(f"esp32 esta dando problema: {e}")
        return None




def get_data(Id):
    try:
        url = 'https://www.amiiboapi.com/api/amiibo/?id=' + Id
        response = requests.get(url)

        
        response.raise_for_status()

        
        return response.json()

    except requests.exceptions.RequestException as e:
        print(f"Error fetching data: {e}")
        return {}
    


