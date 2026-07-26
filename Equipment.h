#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

class Equipment {
public:
    enum class eEquipmentStatus {
        WORKING,
        DAMAGED
    };

private:
    std::string name;
    std::string serialNumber;
    int quantity;
    eEquipmentStatus status;

public:
    Equipment(const std::string& name,
              const std::string& serialNumber,
              int quantity,
              eEquipmentStatus status);
    Equipment(Equipment&& other) noexcept;
    Equipment& operator=(Equipment&& other) noexcept;
    ~Equipment();

    Equipment(const Equipment& other) = delete;
    Equipment& operator=(const Equipment& other) = delete;

    const std::string& getName() const;
    const std::string& getSerialNumber() const;
    int getQuantity() const;
    eEquipmentStatus getStatus() const;

    bool setName(const std::string& name);
    bool setSerialNumber(const std::string& serialNumber);
    bool setQuantity(int quantity);
    bool setStatus(eEquipmentStatus status);
    void print() const;
    friend std::ostream& operator<<(std::ostream& os, const Equipment& eq);
};

#endif // EQUIPMENT_H
