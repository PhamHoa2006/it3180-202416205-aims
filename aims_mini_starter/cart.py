MAX_NUMBERS_ORDERED = 20


class Cart:
    """Giỏ hàng chứa tối đa MAX_NUMBERS_ORDERED đĩa DVD."""

    def __init__(self):
        self.items = []

    def add_dvd(self, dvd):
        if len(self.items) >= MAX_NUMBERS_ORDERED:
            print("The cart is almost full")
            return False
        self.items.append(dvd)
        print("The disc has been added")
        return True

    def remove_dvd(self, dvd):
        if dvd in self.items:
            self.items.remove(dvd)
            print("The disc has been removed")
            return True
        print("The disc is not in the cart")
        return False
    def print_cart(self):
        if not self.items:
            print("The cart is empty")
        for item in self.items: 
            print(item.title)
        return True

    def total_cost(self):
        return sum(item.cost for item in self.items)

    def total_cost_with_discount(self, percent):
        if (not isinstance(percent, (int, float)) or percent > 100 or percent < 0):
            raise ValueError("Percent invalid")
        total = self.total_cost()
        return total * (1 - percent / 100.0)