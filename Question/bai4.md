# Trả lời bài 4

## 1. Vì sao `release/*` không merge ngược vào `master`?

* Định hướng luồng mã nguồn (Upstream direction):** Trong mô hình Release Flow của học phần, `master` đóng vai trò là dòng phát triển chính và luôn tiến về phía trước. Mọi công việc chuẩn bị cho bản phát hành (như cập nhật phiên bản, viết CHANGELOG, sửa lỗi) đều đã được chuẩn bị và hợp nhất trên `master` trước khi rẽ nhánh `release/*`.

* Tránh rác lịch sử và xung đột dư thừa:** Vì nhánh `release/*` chỉ được tạo ra ở bước cuối cùng để làm cột mốc đóng băng nộp bài (baseline), việc merge ngược từ `release/*` về `master` không mang lại mã nguồn mới nào mà chỉ tạo thêm các commit merge thừa, gây rối cây lịch sử Git.

---

## 2. So sánh quy trình Release Flow (trong học phần) với GitFlow

* **Cấu trúc nhánh dài hạn (Long-lived branches):**
  * **Release Flow:** Chỉ duy nhất **1 nhánh** sống dài hạn là `master`. Mọi tính năng hay sửa lỗi đều xuất phát từ `master` và gộp trực tiếp về `master`.
  * **GitFlow:** Duy trì song song **2 nhánh** sống dài hạn là `main` (chứa các bản mã nguồn đã phát hành) và `develop` (dòng tích hợp chính cho mã nguồn đang phát triển).

* **Luồng di chuyển của bản Release:**
  * **Release Flow:** Nhánh `release/*` được rẽ ra trực tiếp từ `master` khi dự án đã sẵn sàng phát hành để đóng băng mã nguồn (đánh tag, nộp bài). Nhánh này **không merge ngược** lại `master`.
  * **GitFlow:** Nhánh `release/*` được rẽ ra từ `develop`. Sau khi chuẩn bị phát hành xong, nhánh `release/*` phải được **merge song song vào cả 2 nhánh**: vừa merge vào `main` (để đánh tag release) vừa merge ngược về `develop` (để cập nhật lại các chỉnh sửa).

* **Độ phức tạp & Tần suất phát hành (Release cadence):**
  * **Release Flow:** Đơn giản, linh hoạt, theo triết lý Trunk-based Development. Rất phù hợp cho các mô hình Tích hợp & Giao hàng liên tục (CI/CD) với tần suất phát hành nhanh (hàng ngày hoặc hàng tuần).

  * **GitFlow:** Phức tạp hơn, tốn chi phí quản lý nhánh và giải quyết xung đột khi số lượng developer lớn. Phù hợp với các sản phẩm đóng gói truyền thống (như phần mềm đóng gói, ứng dụng di động) có chu kỳ phát hành định kỳ, cố định và nhiều phiên bản cần bảo trì đồng thời.

---

## 3. Vì sao phiên bản nâng thẳng lên `1.0.0` mà không phải `0.4.0`?

* **Định nghĩa giai đoạn theo Semantic Versioning (SemVer):** Các số phiên bản dạng `0.y.z` (như `v0.1.0` đến `v0.3.0` từ Lab 01 đến Lab 03) đại diện cho giai đoạn thử nghiệm/phát triển ban đầu (Initial Development), mã nguồn chưa ổn định và giao diện/API có thể thay đổi liên tục.

* **Cột mốc sản phẩm chính thức (Production Baseline):** Đến Lab 04, dự án đã đạt đầy đủ các tính năng cốt lõi (xem giỏ hàng, tìm kiếm, tính giảm giá, sửa các lỗi giới hạn và sắp xếp) cùng hệ thống unit test hoàn chỉnh. Khi sản phẩm đạt trạng thái sẵn sàng cho người dùng cuối (General Availability / Production Ready), theo chuẩn SemVer, số phiên bản **MAJOR** phải được nâng lên **`1.0.0`** để khẳng định tính ổn định của sản phẩm.
