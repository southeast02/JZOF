from itertools import compress, imap


def fun(lst):
    min_number = 100000000
    length = len(lst)
    total = 2**length
    record = None
    # compress('ABCDEF', [1,0,1,0,1,1]) --> A C E F
    # bin(5) = 0b101, so bin(5)[2:] is the string
    select_list_by_n = lambda n:compress(lst, imap(int,bin(n)[2:].rjust(length,'0')))
    for n in xrange(total):
        # ensure the two lists have same amount of numbers
        if not is_half(n, length):
            continue
        list1 = select_list_by_n(n)
        list2 = select_list_by_n(total-n-1)
        tmp = abs(sum(list1) - sum(list2))
        if tmp < min_number:
            record = n
            min_number = tmp

    list1 = list(select_list_by_n(record))
    list2 = list(select_list_by_n(total-record-1))
    return (list1, list2, min_number)


def is_half(n, length):
    """ Judge whether the number of '1' in  bin(n) is equal to half of length.

    :param n: integer
    :param length: integer
    :return: True: (number of '1' in bin(n) equals to half of length)
             False: amount no equal
    """
    half = length / 2
    num_of_1 = count_1(n)

    if num_of_1 == half:
        return True
    return False


def count_1(n):
    """Compute the number of '1' in bin(n)

    :param n: an integer
    :return: an integer: number of '1' in bin(n)
    """
    count = 0
    while n != 0:
        count += 1
        n = (n & (n-1))
    return count


def main():
    n = int(raw_input())
    a = []
    b = raw_input().split()

    if not (n == len(b)):
        print "error: need %d integers in list" % n
        return

    for e in b:
        a.append(int(e))

    list1, list2, dist = fun(a)
    print list1, list2, dist

main()

"""

output

4
8 2 2 4
[2, 4] [8, 2] 4

6
12 4 3 9 8 5
[3, 9, 8] [12, 4, 5] 1

"""
