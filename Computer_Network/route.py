import csv

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

def function1(local_route_list,route_list,local_route_id,route_id):
    for route in route_list:
        flag = 0
        if route['目的地址'] == local_route_id:
            continue
        for local_route in local_route_list:
            if local_route['目的地址'] == route['目的地址'] and int(route['距离']) + 1 < int(local_route['距离']):
                local_route['下一跳'] = route_id
                local_route['距离'] = str(int(route['距离']) + 1)
                flag = 1
                break
            elif local_route['目的地址'] == route['目的地址'] and int(route['距离']) + 1 >= int(local_route['距离']):
                flag = 1 
                break
        if flag == 0:
            route['距离'] = str(int(route['距离']) + 1)
            route['下一跳'] = route_id
            local_route_list.append(route)
    return local_route_list


if __name__ == '__main__':
    As = csv2dict('test.csv')
    Bs = csv2dict('test1.csv')
    dict2csv_save('test2.csv',function1(As,Bs,'A','B'))
