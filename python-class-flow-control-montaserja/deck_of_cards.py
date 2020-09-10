import random

class cardsDeck:
    def __init__(self):
        self.deck = [(i, cardtype) for cardtype in ['Spade', 'Heart', 'Diamond', 'Club'] for i in range(1, 14)]
        self.index = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.index >= len(self.deck):
            self.index = 0
            raise StopIteration
        index = self.index
        self.index += 1
        return self.deck[index]

    def draw(self):
        return self.deck.pop()

    def put_back(self, card):
        self.deck.append(card)

    def shuffleCards(self):
        random.shuffle(self.deck)

class player:
    def __init__(self,num):
        self.playerNum=num
        self.cards = []

    def draw(self,card):
        self.cards.append(card)

    def put_back(self):
        return self.cards.pop()

    def get_cards(self):
        return self.cards

    def get_player_num(self):
        return self.playerNum

class game:
    def __init__(self):
        self.players=[player(i) for i in range(1,5)]
        self.deck= cardsDeck()
        self.deck.shuffleCards()

    def players_take_cards(self):
        for player in self.players:
            for _ in range(7):
                player.draw(self.deck.draw())

    def players_return_one_card(self):
        for player in self.players:
                self.deck.put_back(player.put_back())

    def print_players_cards(self):
        for player in self.players:
            print("player" + str(player.get_player_num()) + "cards : " )
            for card in player.get_cards():
                print(card)







if __name__ == '__main__':
    c = cardsDeck()
    for card in c:
        print(card)

    game = game()
    game.players_take_cards()
    game.print_players_cards()
    game.players_return_one_card()
    game.print_players_cards()
