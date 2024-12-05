#include<stdio.h> 

int main() {
    int choice;
    int arr[100], n;
    int i, j;
    int temp;
    int div;
    while (1) {
        printf("-----MENU-----\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong cac so hoan hao trong mang\n");
        printf("4. Tim gia tri lon thu 2 trong mang\n");
        printf("5. Them phan tu vao vi tri ngau nhien\n");
        printf("6. Xoa phan tu tai vi tri\n");
        printf("7. Sap xep mang theo thu tu tang dan (Insertion sort)\n");
        printf("8. Tim kiem phan tu trong mang (Binary search)\n");
        printf("9. Sap xep mang: so chan truoc so le sau\n");
        printf("10. Dao nguoc thu tu cac phan tu trong mang\n");
        printf("11. Thoat\n");
        printf("\nLua chon cua ban la: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Moi ban nhap so phan tu cho mang: ");
                scanf("%d", &n);
                
                if (n <= 0) {
                    printf("So phan tu khong hop le. Moi nhap lai.\n");
                    break;
                }
                
                for (i = 0; i < n; i++) {
                    printf("Nhap gia tri cho arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                printf("Gia tri cac phan tu trong mang:\n");
                for (i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;

            case 3:
                {
                    int count = 0;
                    for (i = 0; i < n; i++) {
                        int sum = 0;
                        for (div = 1; div <= arr[i] / 2; div++) {
                            if (arr[i] % div == 0) {
                                sum += div;
                            }
                        }
                        if (sum == arr[i] && arr[i] != 0) {
                            count++;
                        }
                    }
                    printf("So luong cac so hoan hao trong mang: %d\n", count);
                }
                break;

            case 4:
                {
                    int max1 = arr[0], max2 = -1;
                    for (i = 1; i < n; i++) {
                        if (arr[i] > max1) {
                            max2 = max1;
                            max1 = arr[i];
                        } else if (arr[i] > max2 && arr[i] != max1) {
                            max2 = arr[i];
                        }
                    }
                    if (max2 != -1) {
                        printf("Gia tri lon thu 2 trong mang: %d\n", max2);
                    } else {
                        printf("Khong co gia tri lon thu 2.\n");
                    }
                }
                break;

            case 5:
                {
                    int value, position;
                    printf("Nhap gia tri phan tu can them: ");
                    scanf("%d", &value);
                    printf("Nhap vi tri can them (0 den %d): ", n);
                    scanf("%d", &position);

                    if (position < 0 || position > n) {
                        printf("Vi tri khong hop le.\n");
                        break;
                    }

                    for (i = n; i > position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position] = value;
                    n++;
                    printf("Da them phan tu %d vao vi tri %d.\n", value, position);
                }
                break;

            case 6:
                {
                    int position;
                    printf("Nhap vi tri phan tu can xoa (0 den %d): ", n - 1);
                    scanf("%d", &position);

                    if (position < 0 || position >= n) {
                        printf("Vi tri khong hop le.\n");
                        break;
                    }

                    for (i = position; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Da xoa phan tu tai vi tri %d.\n", position);
                }
                break;

            case 7:
                {
                    
                    for (i = 1; i < n; i++) {
                        temp = arr[i];
                        int j = i - 1;
                        while (j >= 0 && arr[j] > temp) {
                            arr[j + 1] = arr[j];
                            j--;
                        }
                        arr[j + 1] = temp;
                    }
                    printf("Mang sau khi sap xep theo thu tu tang dan:\n");
                    for (i = 0; i < n; i++) {
                        printf("arr[%d] = %d\n", i, arr[i]);
                    }
                }
                break;

            case 8:
                {
                    int key, left = 0, right = n - 1, mid;
                    printf("Nhap phan tu can tim: ");
                    scanf("%d", &key);

                    while (left <= right) {
                        mid = (left + right) / 2;
                        if (arr[mid] == key) {
                            printf("Phan tu %d da tim thay tai vi tri %d.\n", key, mid);
                            break;
                        } else if (arr[mid] < key) {
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }

                    if (left > right) {
                        printf("Phan tu %d khong ton tai trong mang.\n", key);
                    }
                }
                break;

            case 9:
                {
                    int ch, le;
                    int new_arr[100], even_count = 0, odd_count = 0;

                    for (i = 0; i < n; i++) {
                        if (arr[i] % 2 == 0) {
                            new_arr[even_count++] = arr[i];
                        } else {
                            new_arr[odd_count++] = arr[i];
                        }
                    }

                    for (i = 0; i < even_count; i++) {
                        arr[i] = new_arr[i];
                    }
                    for (i = 0; i < odd_count; i++) {
                        arr[even_count + i] = new_arr[even_count + i];
                    }

                    printf("Mang sau khi sap xep chan truoc, le sau:\n");
                    for (i = 0; i < n; i++) {
                        printf("arr[%d] = %d\n", i, arr[i]);
                    }
                }
                break;

            case 10:
                {
                    for (i = 0; i < n / 2; i++) {
                        temp = arr[i];
                        arr[i] = arr[n - i - 1];
                        arr[n - i - 1] = temp;
                    }

                    printf("Mang sau khi dao nguoc:\n");
                    for (i = 0; i < n; i++) {
                        printf("arr[%d] = %d\n", i, arr[i]);
                    }
                }
                break;

            case 11:
                printf("Thoat chuong trinh.\n");
                return 0;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}
	 
