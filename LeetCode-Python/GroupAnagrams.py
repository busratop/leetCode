class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # defaultdict kullanarak bir default dict oluşturuyoruz
        mp = defaultdict(list)

        # strs içindeki her bir kelimeyi işliyoruz
        for word in strs:
            # Kelimenin sıralanmış halini alıyoruz
            sorted_word = ''.join(sorted(word))
            # Sıralanmış kelimeyi anahtar olarak kullanarak kelimeyi ilgili gruba ekliyoruz
            mp[sorted_word].append(word)

        # mp içindeki tüm grupları bir liste olarak döndürüyoruz
        return list(mp.values())
