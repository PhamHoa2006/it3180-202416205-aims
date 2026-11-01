import unittest


from aims_mini_starter.cart import Cart
from aims_mini_starter.dvd import DigitalVideoDisc

class TestCartLimit(unittest.TestCase):
    def test_add_dvd_full(self):
        cart = Cart()
        for i in range(20):
            self.assertTrue(cart.add_dvd(DigitalVideoDisc(f"DVD {i}")))
        self.assertFalse(cart.add_dvd(DigitalVideoDisc("DVD 21")))

if __name__ == '__main__':
    unittest.main()