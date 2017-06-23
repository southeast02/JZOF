
class Cmp:
    def cmp(self, g1, g2, records, n):
        less1 = set()
        greater1 = set()

        less2 = set()
        greater2 = set()

        for pair in records:
            v1 = pair[0]
            v2 = pair[1]
            if(v1 == g1):
                less1.add(v2)
            elif(v2 == g1):
                greater1.add(v1)

            if (v1 == g2):
                less2.add(v2)
            elif (v2 == g2):
                greater2.add(v1)
        # if(not(less1-greater2)):
        if(less1.intersection(greater2)) or g1 in greater2 or g2 in less1:
            return 1
        # if(not(less2-greater1)):
        if(less2.intersection(greater1)) or g1 in less2 or g2 in greater1 :
            return -1
        return 0

# input: 2,3, [[1,2], [2,4], [1,3], [4,3]], 4
# output: 1
