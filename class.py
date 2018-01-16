'''
所有类的实例，共享方法，不共享属性
每个方法的第一个参数都是self(调用对象的实例)

'''

import  os

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

class Athlete:
    def __init__(self, a_name=None, a_dob=None, a_times=[]):
        self.name = a_name
        self.dob = a_dob
        self.times = a_times

    def top3(self):
        #print (self.name + "'s fastest times: " + str(sorted(set([sanitize(t) for t in self.times]))[0:3]))
        return  sorted(set([sanitize(t) for t in self.times]))[0:3]

    def add_time(self, time): #添加一个时间
        self.times.append(time)

    def add_times(self, Times): #添加一组时间，['5.56', '3.12']
        self.times.extend(Times)

    def get_coach_data(self, filename):
        try:
            fdata =  open(filename, mode='r', encoding='utf-8')
        except IOError as err:
            print ("open file error " + str(err))
        try:
            for ec in fdata:
                datas = ec.strip().split(',')
                self.name = datas.pop(0)
                self.dob = datas.pop(0)
                self.times = datas

        except ValueError as err:
            print ("file data error " + str(err))

        finally:
            fdata.close()


if __name__ == "__main__":
    james = Athlete()
    james.get_coach_data(file_james)
    print (james.name + "'s fastest times " + str(james.top3()))
    julie = Athlete()
    julie.get_coach_data(file_julie)
    print (julie.name + "'s fastest times " + str(julie.top3()))
    mikey = Athlete()
    mikey.get_coach_data(file_mikey)
    print (mikey.name + "'s fastest times " + str(mikey.top3()))
    sarah = Athlete()
    sarah.get_coach_data(file_sarah)
    print (sarah.name + "'s fastest times " + str(sarah.top3()))