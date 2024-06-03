from collections import Counter

vec = {
    'a': 1,
    'b': 2,
    'c': 4,
    'd': 8,
    'e': 16,
    'f': 32,
    'g': 64,
    'h': 128,
    'i': 256,
    'j': 512
}
vv = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512}

def wonderfulSubstrings(word: str) -> int:
    ans = 0
    ll = len(word)

    for i in range(ll):
        if i == 0:
            sdict = [vec[word[0]]]
            for l in word[1:]:
                sdict.append(sdict[-1] ^ vec[l])

        for v in sdict:
            ans += 1 if v in vv else 0

        letter = word[0]
        word = word[1:]
        sdict = sdict[1:]
        for i in range(len(sdict)):
            sdict[i] = sdict[i] ^ vec[letter]

    return ans

print(wonderfulSubstrings("aabb"))
