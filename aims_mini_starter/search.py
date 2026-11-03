from dvd import DigitalVideoDisc
from cart import Cart
def search_by_category(items, category):
    if not category or not isinstance(category, str):
        return []
    cat_lower = category.strip().lower()
    return [item for item in items if hasattr(item, 'category') and item.category and cat_lower in item.category.lower()]
def search_by_title(items, title):
    """Hàm tìm kiếm bị lỗi: phân biệt chữ hoa và chữ thường."""
    if not title or not isinstance(title, str):
        return []
    return [item for item in items if hasattr(item, 'title') and item.title and title in item.title]

    