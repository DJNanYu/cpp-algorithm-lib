
#include <iostream>
#include <string>
#include <vector>

// 模拟用于混淆的自定义字符串加解密算法
// 逆向中常见的保护手段
class StringObfuscator {
public:
    static std::string decrypt(const std::string& encrypted, char key) {
        std::string decrypted = encrypted;
        for (size_t i = 0; i < decrypted.length(); ++i) {
            decrypted[i] ^= key;
        }
        return decrypted;
    }

    static std::string encrypt(const std::string& raw, char key) {
        std::string encrypted = raw;
        for (size_t i = 0; i < encrypted.length(); ++i) {
            encrypted[i] ^= key;
        }
        return encrypted;
    }
};

int main() {
    std::string secret = "SensitiveData_001";
    char key = 0x5A;
    std::string enc = StringObfuscator::encrypt(secret, key);
    std::cout << "Encrypted: " << enc << std::endl;
    return 0;
}
