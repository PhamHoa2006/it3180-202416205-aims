# Tra loi cau hoi

## 1. Ưu và nhược điểm của Upstream First (sửa ở master trước) so với Release First (sửa ở release trước)?

* **Release First :**
  * *Ưu điểm:* Tối ưu thời gian khắc phục sự cố nghiêm trọng cho người dùng Production; chỉ sửa đúng mã bị lỗi mà không bị ảnh hưởng bởi mã nguồn mới chưa ổn định trên `master`.
  * *Nhược điểm:* Phải tốn thêm thao tác `cherry-pick -x` để lan truyền bản sửa ngược lại các nhánh phát triển khác (`main`, `release/*`), dễ bị bỏ quên nếu không kiểm toán kỹ.
* **Upstream First:**
  * *Ưu điểm:* Tránh triệt để tình trạng bỏ quên bản vá trên nhánh chính `master`.
  * *Nhược điểm:* Khó áp dụng nếu nhánh `master` đang có nhiều thay đổi lớn hoặc cấu trúc dự án trên `master` đã khác xa so với bản đang phát hành.

---

## 2. Nếu quên lan truyền bản sửa sang `release/lab05`, lệnh nào ở Phần F sẽ phát hiện?

* Lệnh **`git cherry -v origin/main origin/release/lab05`** hoặc **`git tag --contains <FIX_SHA>`** sẽ phát hiện ra điều này.
