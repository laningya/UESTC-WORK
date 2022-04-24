import csv
import json

def csv2dict(filename):
    devices_dict = []
    with open(filename,'r') as f:
        csvreader = csv.reader(f)
        header = next(csvreader)
        for device_csv in csvreader:
            result = dict(zip(header,device_csv))
            devices_dict.append(result)
    return devices_dict

def dict2csv_save(filename,devices_dict):
    header = devices_dict[0].keys()
    devices_csv = []
    for device_dict in devices_dict:
        result = device_dict.values()
        devices_csv.append(result)
    with open(filename,'w') as f:
        f_csv = csv.writer(f)
        f_csv.writerow(header)
        f_csv.writerows(devices_csv)

def json2dict(filename):
    devices_dict = []
    with open(filename,'r') as f:
        jsonreader = json.load(f)
        for device_json in jsonreader:
            devices_dict.append(device_json)
    return devices_dict

def dict2json_save(filename,devices_dict):
    with open(filename,'w') as f:
        json.dump(devices_dict,f)

def csv2json(filename1,filename2):
    dict2json_save(filename2,csv2dict(filename1))

def json2csv(filename1,filename2):
    dict2csv_save(filename2,json2dict(filename1))