import os

man = []
others = []

try:
    with open("sketch.txt", mode='r', encoding='utf-8') as data:
    #data = open("sketch.txt", mode='r')
        data.seek(0)
        try:
            for each_line in data:
                (first, second) = each_line.split(':', 1)
                man.append(first)
                others.append(second)
        except ValueError as err:
            print ("value error " + str(err))
    with open("man.txt", mode='w', encoding='utf-8') as man_file:
        for each in man:
            print (each, file=man_file)

    with open("others.txt", mode='w', encoding='utf-8') as others_file:
        for each in others:
            print (each, file=others_file)

except IOError as err:
    print ("file err " + str(err))

finally:
    data.close()