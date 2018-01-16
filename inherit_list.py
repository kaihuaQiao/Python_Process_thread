'''
继承list
'''

import os

file_james = "hfpy_ch6_data/james2.txt"
file_julie = "hfpy_ch6_data/julie2.txt"
file_mikey = "hfpy_ch6_data/mikey2.txt"
file_sarah = "hfpy_ch6_data/sarah2.txt"

def sanitize(time_string):
    if '-' in time_string:
        splitter = '-'
    elif ':' in time_string:
        splitter = ':'
    else:
        return (time_string)

    (mins, secs) = time_string.split(splitter)
    return (mins + '.' + secs)

class AthleteList(list):
    def __init__(self, a_name=None, a_dob=None, a_times=[]):
        list.__init__([])
        self.name = a_name
        self.dob = a_dob
        self.extend(a_times)

    def top3(self):
        return sorted(set([sanitize(t) for t in self]))[0:3]

def get_cocah_data(filename):
    try:
        fdata = open(filename, mode='r', encoding='utf-8')
    except IOError as err:
        print("open file error " + str(err))
    try:
        for ec in fdata:
            ffd = ec.strip().split(',')
            return AthleteList(ffd.pop(0), ffd.pop(0), ffd)

    except ValueError as err:
        print("file data error " + str(err))

    finally:
        fdata.close()


if __name__ == '__main__':
    james = get_cocah_data(file_james)
    print (james.name + "'s fastest times: " + str(james.top3()))
