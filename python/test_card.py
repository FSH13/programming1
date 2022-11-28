import pytest
from card import Card

def test_cards():
    rank = 8
    suit = 'c'
    expected_card = 'Eight of Clubs'
    assert Card(8, 'c') == expected_card
