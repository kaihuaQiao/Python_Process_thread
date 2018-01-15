import os

file_james = "hfpy_ch6_data/james2.txt"
file_julie = "hfpy_ch6_data/julie2.txt"
file_mikey = "hfpy_ch6_data/mikey2.txt"
file_sarah = "hfpy_ch6_data/sarah2.txt"

data_james = []
data_julie = []
data_mikey = []
data_sarah = []

def sanitize(time_string):
    if '-' in time_string:
        splitter = '-'
    elif ':' in time_string:
        splitter = ':'
    else:
        return (time_string)

    (mins, secs) = time_string.split(splitter)
    return (mins + '.' + secs)

def get_coach_data(filename):
    data = []
    try:
        fdata = open(filename, mode='r', encoding='utf-8')
    except IOError as err:
        print ("file open error " + str(err))
    try:
        for ec in fdata:
            data = ec.strip().split(',')

        return data
    except ValueError as err:
        print ("read file data err " + str(err))
    finally:
        fdata.close()

def get_coach_data2(filename):
    data = {}
    try:
        fdata = open(filename, mode='r', encoding='utf-8')
    except IOError as err:
        print("file open error " + str(err))
    try:
        for ec in fdata:
            datas = ec.strip().split(',')

        data = {'name':datas.pop(0), 'bob':datas.pop(0),
                'data':sorted(set([sanitize(t) for t in datas]))[0:3]}
        return data
    except ValueError as err:
        print("read file data err " + str(err))

    finally:
        fdata.close()

if __name__ == "__main__":
    #data = get_coach_data(file_james)
    #使用列表的处理方式
    #(name, dob) = data.pop(0), data.pop(0)
    #print (name + "'s fastest times are: " + str(sorted(set([sanitize(t) for t in data]))[0:3]))
    #改为字典的处理方式
    #james_dict = dict()
    #james_dict['name'] = data.pop(0)
    #james_dict['bob'] = data.pop(0)
    #james_dict['data'] = data
    #print (james_dict['name'] + "' s fastest times are: " + str(sorted(set([sanitize(t) for t in james_dict['data']]))[0:3]))
    #print (james_dict)
    james_data = get_coach_data2(file_james)
    print (james_data['name'] + "'s fastest times are: " + str(james_data['data']))
    julie_data = get_coach_data2(file_julie)
    print(julie_data['name'] + "'s fastest times are: " + str(julie_data['data']))
    mikey_data = get_coach_data2(file_mikey)
    print(mikey_data['name'] + "'s fastest times are: " + str(mikey_data['data']))
    sarah_data = get_coach_data2(file_sarah)
    print(sarah_data['name'] + "'s fastest times are: " + str(james_data['data']))