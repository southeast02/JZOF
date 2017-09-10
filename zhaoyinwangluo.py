import copy


def addBoldTag(s, dict):
    tagList = []
    tag = {}
    for e in dict:
        if e in s:
            start = s.find(e)
            tag["start"] = start
            tag["end"] = start + len(e) - 1
            tagList.append(copy.deepcopy(tag))
    sorted(tagList, key= lambda x: (x['start'], x['end']))
    # print tagList

    n = len(tagList)
    i = 0
    while i < n-1:
        e1 = tagList[i]
        e2 = tagList[i+1]
        if e1['start']==e2['start'] and e1['end']<e2['end']:
            e1['end'] = e2['end']
            e2['start']=e1['start']
        elif e2['start'] < e1['end']:
            e1['end'] = e2['end']
            e2['start'] = e1['start']
        elif e2['start']-1==e1['end']:
            e1['end'] = e2['end']
            e2['start'] = e1['start']
        i = i + 1
    # print tagList

    # remove duplicate
    i = 0
    count = 0
    while i+count < n-1:
        if i == n-1-count:
            break
        e1 = tagList[i]
        e2 = tagList[i+1]
        if e1['start']==e2['start'] and e1['end']<=e2['end']:
            tagList.remove(e1)
            count += 1
            continue
        i += 1
    print tagList

    tags = 0
    for e in tagList:
        if e['start'] == 0:
            s = '<b>' + s[e['start'] + 7 * tags:e['end'] + 7 * tags + 1] + '</b>' + s[e['end'] + 7 * tags + 1:]
        else:
            s = s[:e['start'] + 7*tags ] + '<b>' + s[e['start']+ 7*tags:e['end']+ 7*tags + 1] + '</b>' + s[e['end']+ 7*tags + 1:]
        tags += 1
    print s


s1 = "abcxyz123"
dict1 = ["abc", "123"]

s2 = "aaabbcc"
dict2 = ["aaa", "aab", "bc"]

s3 = "zhubajie"
dict3=["zhu", "ba", "jie"]

addBoldTag(s2, dict2)
addBoldTag(s1, dict1)
addBoldTag(s3, dict3)

# output:
# <b>aaabbc</b>c
# <b>abc</b>xyz<b>123</b>
# <b>zhubajie</b>
