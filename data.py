import os

file_james = "hfpy_ch5_data/james.txt"
file_julie = "hfpy_ch5_data/julie.txt"
file_mikey = "hfpy_ch5_data/mikey.txt"
file_sarah = "hfpy_ch5_data/sarah.txt"

data_james = []
data_julie = []
data_mikey = []
data_sarah = []

unique_james = []
unique_julie = []
unique_mikey = []
unqiue_sarah = []

def get_data(filename):
    data = []
    try:
        fdata = open(filename, mode='r', encoding='utf-8')
    except IOError as err:
        print ("file open error " + str(err))
    try:
        for each in fdata:
           #print (each)
           data = each.strip().split(",")


    except ValueError as err:
        print ("data error " + str(err))

    #for ee in data:
     #   ee.strip()
      #  print (ee)

    return data
'''
def sanitize(time_string):
    dd = time_string.find('-')
    #print (time_string)
    if not dd == -1:
        min = time_string[0:dd]
        sec = time_string[dd + 1:]
        return min + "." + sec
    dd = time_string.find(':')
    if not dd == -1:
        min = time_string[0:dd]
        sec = time_string[dd + 1:]
        return (min + "." + sec)

    return time_string
'''

def sanitize(time_string):
    if '-' in time_string:
        spli = '-'
    elif ':' in time_string:
        spli = ":"
    else:
        return time_string

    (mins, sec) = time_string.split(spli)

    return (mins + "." + sec)

def modify_data(data):
    datad = []
    for each in data:
        datad.append(sanitize(each))

    return datad

def spilter_repeat_data(datas):
    undata = []
    for ec in datas:
        if ec not in undata:
            undata.append(ec)

    return undata


if __name__ == '__main__':
    #str = "2-34,3:21,2.34,2.45,3.01,2:01,2:01,3:10,2-22"
    data_james = get_data(file_james)
    #data_james1 = sorted(modify_data(data_james))
    data_james1 = []
    data_james1 = [sanitize(ec) for ec in data_james] #列表推到
    #data_james1.sort()
    #unique_james = spilter_repeat_data(data_james1)
    #print(unique_james[0:3])
    set_james = set(data_james1)    #使用集合没有重复元素的特点实现，去除重复元素的功能
    print (sorted(set_james)[0:3])
    data_julie = get_data(file_julie)
    data_julie1 = sorted(modify_data(data_julie))
    unique_julie = spilter_repeat_data(data_julie1)
    print (unique_julie[0:3])
    data_mikey = get_data(file_mikey)
    data_mikey1 = sorted(modify_data(data_mikey))
    unique_mikey = spilter_repeat_data(data_mikey1)
    print (unique_mikey[0:3])
    data_sarah = get_data(file_sarah)
    data_sarah1 = sorted(modify_data(data_sarah))
    unqiue_sarah = spilter_repeat_data(data_sarah1)
    print (unqiue_sarah[0:3])


