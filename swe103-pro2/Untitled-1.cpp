#!/bin/bash

# Renk Tanımlamaları
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # Renksiz (Reset)

# Seçenekler Dizisi (0: Taş, 1: Kağıt, 2: Makas)
secenekler=("Taş" "Kağıt" "Makas")

skor_oyuncu=0
skor_bilgisayar=0

echo -e "${BLUE}====================================${NC}"
echo -e "${YELLOW}  TAŞ - KAĞIT - MAKAS OYUNUNA HOŞ GELDİNİZ  ${NC}"
echo -e "${BLUE}====================================${NC}"

while true; do
    echo -e "\n${BLUE}Mevcut Skor -> Siz: ${GREEN}$skor_oyuncu${NC} | Bilgisayar: ${RED}$skor_bilgisayar${NC}"
    echo "------------------------------------"
    echo "1) Taş"
    echo "2) Kağıt"
    echo "3) Makas"
    echo "4) Çıkış"
    read -p "Seçiminiz (1-4): " secim

    case $secim in
        1) oyuncu_secim=0 ;;
        2) oyuncu_secim=1 ;;
        3) oyuncu_secim=2 ;;
        4) 
            echo -e "\n${YELLOW}Oyun bitti! Oyunu oynadığınız için teşekkürler.${NC}"
            echo -e "Son Skor -> Siz: ${GREEN}$skor_oyuncu${NC} | Bilgisayar: ${RED}$skor_bilgisayar${NC}\n"
            exit 0
            ;;
        *)
            echo -e "${RED}Geçersiz seçim! Lütfen 1, 2, 3 veya 4 girin.${NC}"
            continue
            ;;
    es me

    # Bilgisayarın rastgele seçimi (0, 1 veya 2)
    bilgisayar_secim=$((RANDOM % 3))

    echo -e "\nSizin seçiminiz: ${YELLOW}${secenekler[$oyuncu_secim]}${NC}"
    echo -e "Bilgisayarın seçimi: ${YELLOW}${secenekler[$bilgisayar_secim]}${NC}"

    # Kazananı Belirleme
    if [ $oyuncu_secim -eq $bilgisayar_secim ]; then
        echo -e "${YELLOW}👉 Berabere!${NC}"
    elif [ $(( (oyuncu_secim + 1) % 3 )) -eq $bilgisayar_secim ]; then
        echo -e "${RED}👉 Bilgisayar kazandı!${NC}"
        ((skor_bilgisayar++))
    else
        echo -e "${GREEN}👉 Tebrikler, siz kazandınız!${NC}"
        ((skor_oyuncu++))
    fi
done