import difflib

class choice:
    def __init__(self):
        self.ratio = 0
        self.name = ''

    def refresh(self, ratio, name):
        if self.ratio < ratio:
            self.ratio = ratio
            self.name = name

    def search_list(name_list, target_list):

        target = choice()
        for n in name_list:
            for tmp in target_list:
                seq = difflib.SequenceMatcher(None, n, tmp)
                target.refresh(seq.ratio(), tmp)

        return target.name

    def search(name, target_list):
        return choice.search_list([name], target_list)


