#include <stdio.h>

// Khai báo cấu trúc quản lý thiết bị thông minh
struct SmartDevice {
    int id;
    float voltage;      // Điện áp (V)
    float current;      // Dòng điện (A)
    float power_watt;   // Công suất tiêu thụ (W)
    int is_active;      // Trạng thái thiết bị: 1 - Bật, 0 - Tắt
    int is_overloaded;  // Cảnh báo quá tải: 1 - Quá tải, 0 - An toàn
};

int main() {
    // Khởi tạo thông tin thiết bị Bình Nóng Lạnh
    struct SmartDevice heater;
    heater.id = 101;
    heater.voltage = 220.0f;
    heater.current = 35.0f;     // Cảm biến ghi nhận dòng điện 35A (vượt ngưỡng 30A)
    heater.is_active = 1;       // Người dùng bấm BẬT thiết bị
    heater.is_overloaded = 0;   // Mặc định ban đầu an toàn

    // Kiểm tra quy tắc an toàn quá tải dòng điện (> 30A) trước khi tính công suất
    if (heater.current > 30.0f) {
        heater.is_overloaded = 1;
        heater.is_active = 0;       // Tự động ngắt điện thiết bị
        heater.power_watt = 0.0f;   // Ngay khi ngắt điện, công suất bắt buộc về 0.0W
    } else {
        heater.is_overloaded = 0;
        // Nếu thiết bị đang bật, tiến hành tính công suất tiêu thụ điện
        if (heater.is_active) {
            heater.power_watt = heater.voltage * heater.current;
        } else {
            heater.power_watt = 0.0f;
        }
    }

    // In thông số thiết bị ra màn hình ứng dụng IoT
    printf("=== HỆ THỐNG GIÁM SÁT THIẾT BỊ SMART HOME ===\n");
    printf("Mã thiết bị: %d\n", heater.id);
    printf("Trạng thái hoạt động: %s\n", heater.is_active ? "BẬT" : "TẮT");
    printf("Công suất tiêu thụ: %.2f W\n", heater.power_watt);
    printf("Cảnh báo quá tải (>30A): %s\n", heater.is_overloaded ? "CÓ (ĐÃ NGẮT ĐIỆN)" : "KHÔNG");

    return 0;
}
