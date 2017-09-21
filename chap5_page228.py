def compare_rule(str1, str2):
    a = str1 + str2
    b = str2 + str1

    if a > b:
        return 1
    elif a == b:
        return 0
    else:
        return -1


def print_min_number(numbers):
    str_list = [str(x) for x in numbers]
    sorted_str_list = sorted(str_list, compare_rule)

    str_rn = ''
    for number in sorted_str_list:
        str_rn = str_rn + str(number)
    print str_rn

a = [3, 32, 321]
print_min_number(a)

# output
# 
# 321323
