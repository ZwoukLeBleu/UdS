import objprint as op
import math
dict_a = {'un': 1, 'deux': 2, 'trois': 3}
dict_b = {'a': 4, 'b': 5, 'c': 6}
dict_c = {'a': 7, 'b': 8, 'c': 9}
dict_tot = {'A': dict_a, 'B': dict_b, 'C': dict_c}


class TextAn():
    
    PONC = ["!", ";", ":", ",", ".", "...", "?", "—", "-", "/", "\\", "(", ")", "[", "]", "{", "}", "'"]
    
    def print_dict(dict: dict) -> None:
        for x in dict:
            print (x)
            
        for y in dict[x]:
            print (y,':',dict[x][y])
            

    # * OK
    @staticmethod
    def get_vector_size(dict_de_ngrams: dict) -> float:
        size = 0
        for key in dict_de_ngrams:
            size += pow(dict_de_ngrams[key], 2)
        size = math.sqrt(size)
        return size

    def normalize_vector(self, dict_de_ngrams: dict) -> dict:
        norm_dict = {}
        total_sum = sum(dict_de_ngrams.values())
        for key in dict_de_ngrams:
            norm_dict[key] = dict_de_ngrams[key] / total_sum
        return norm_dict

    @staticmethod
    def add_dict(dict1: dict, dict2: dict) -> dict:
        
        for key, value in dict2.items():
            if key in dict1:
                dict1[key] += value
            else:
                dict1[key] = value
        
        return dict1

    @staticmethod
    def dot_product_dict(dict1: dict, dict2: dict) -> float:
        #Il faudrait surment plein de verifications dans des try thow exceptions pour pas planter la patente
        sum = 0
        for key in dict1:
            if key in dict2:
                sum += dict1[key]*dict2[key]
        return sum
            
    # def find_author(self, oeuvre: str) -> []:
    
    # def get_ngram_occurrence(self, auteur: str, ngram: str) -> int:
    
    # def get_total_occurrences(self, auteur: str) -> int:
    
    # def gen_text_dict(self, auteur_dict: dict, taille: int, to_file: io.TextIOWrapper) -> None:
    
    # def get_kth_element(self, auteur: str, k: int) -> [[str]]:
    
    def analyze(self) -> None:
        # Fait l'analyse des textes fournis, en traitant chaque oeuvre de chaque auteur

        # Args :
        #     void : toute l'information est contenue dans l'objet TextAn

        # Returns :
        #     void : ne retourne rien, toute l'information extraite est conservée dans des structures internes

        # Ajouter votre code ici pour traiter l'ensemble des oeuvres de l'ensemble des auteurs
        # Pour l'analyse :  faire le calcul des occurrences de n-grammes pour l'ensemble des oeuvres
        #   d'un certain auteur, sans distinction des oeuvres individuelles,
        #       et recommencer ce calcul pour chacun des auteurs
        #   En procédant ainsi, les oeuvres comprenant plus de mots auront un impact plus grand sur
        #   les statistiques globales d'un auteur.
        # Il serait possible de considérer que chacune des oeuvres d'un auteur ont un poids identique.
        #   Pour ce faire, il faudrait faire les calculs des occurrences pour chacune des oeuvres
        #       de façon indépendante, pour ensuite les normaliser,
        #       avant de les additionner pour obtenir le vecteur complet d'un auteur
        #   De cette façon, les mots d'un court poème auraient une importance beaucoup plus grande que
        #   les mots d'une très longue oeuvre du même auteur. Ce n'est PAS ce qui vous est demandé ici.
        #
        # Pour chaque auteur, créer un dictionnaire contenant :
        #       les ngrammes comme clé
        #       le nombre d'occurrences comme valeur
        #   Le dictionnaire de chacun des auteurs doit être ajouté à self.ngrams_auteurs, avec l'auteur comme clé

        self.ngrams_auteurs = {}
        for auteur in self.auteurs:
            ngram_counts = {}
            oeuvres = self.get_aut_files(auteur)
            for oeuvre in oeuvres:
                with open(oeuvre, 'r', encoding='utf-8') as f:
                    text = f.read()
                    ngrams = self.get_ngrams(text, 2)
                    for ngram in ngrams:
                        if ngram in ngram_counts:
                            ngram_counts[ngram] += 1
                        else:
                            ngram_counts[ngram] = 1
            self.ngrams_auteurs[auteur] = ngram_counts
        return
        
        
if __name__ == '__main__':
    d = TextAn()
    print(d.get_vector_size(dict_a))
    print(d.normalize_vector(dict_a))
    print(d.dot_product_dict(dict_a, dict_b))
# i=0
# for key in dict_de_ngrams:
#     print(i, '\n')
#     i+=1
# print(i)


