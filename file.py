import os

cdir = os.getcwd()
print (cdir)

if __name__ == '__main__':
    filename = 'concept_checks1.h'

'''
    if os.path.exists(filename):
        data = open(filename, mode='r', encoding='utf-8')
        data.seek(0)
        for each in data:
            print (data.readline(), end='\n')

        data.close()
    else:
        print ("filename error")
'''
try:
    data = open(filename, mode='r', encoding='utf-8')
    data.seek(0)
    #for each in data:
        #print(data.readline(), end='\n')

    data.close()
    try:
        str = "fdfd:fddd:dssss"
        (role, ffff) = str.split(":", 1)
        print(role)
        print(ffff)
    except ValueError:
        pass
except IOError:
    print("filename error")

filew = "copy1.h"

try:
    data = open(filename, mode='r', encoding='utf-8')
    dataw = open(filew, mode='w+', encoding='utf-8')
    for each_line in data:
        each_line = data.readline()
        print(each_line, file=dataw)

    #dataw.close()
    #data.close()
except IOError as err:
    print ("open file error: " + str(err))

finally:
        if 'data' in locals():
            data.close()
        if 'dataw' in locals():
            dataw.close()

try:
    with open(filename, mode='r', encoding='utf-8') as data:
        print (data.readline())
except IOError as err:
    print ("file output error:  " + str(err))
