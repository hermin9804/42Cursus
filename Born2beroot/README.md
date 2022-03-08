# Born2beroot

[notion 정리](https://www.notion.so/Born2beroot-b890cfe216f84b549d68a9fec5cf89e9)

# 개념

[Virtual Machine](https://www.notion.so/Virtual-Machine-551dc2aa2e4c4ea481bb6c83f51d496a)

[CentOS vs Debian](https://www.notion.so/CentOS-vs-Debian-a4a3a09dbbf04fddb1ca3392fd4e04f2) 

[Aptitude vs Apt](https://www.notion.so/Aptitude-vs-Apt-194c53cc0f1e4f79b4b3af5f566caa8c) 

# Mandatory

## Mandatory 설정

- 데비안 11 설치
    
    [데비안 GNU/리눅스 설치 안내서](https://www.debian.org/releases/stable/s390x/index.ko.html)
    
- sudo 설치
    - su -  : root 계정으로 이동하기 위함
    - apt-get update : 패키지 목록 업데이트
    - apt install sudo
- secure_path 설정
    
    서브젝트에는 secure_path를
    
    ```bash
    /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
    ```
    
    로 하라고 되어있기 때문에 /snap/bin 추가 
    
    - visudo로 sudoers에 접근
    - secure_path에 /snap/bin 추가
    - 저장하고 나갈때 .tmp 파일을 생성 하는 이유는 .tmp파일로 저장후 문법에 맞는지 검사하는 과정을 거치기 때문이다.
- 다른 정책들 추가
    
    ```bash
    #sudo를 사용할 때 잘못된 암호로 인한 오류가 발생하면 선택한 사용자 지정 메시지가 표시되어야합다.
    Defaults	authfail_message="Authfail!"
    Defaults	badpass_message="WrongPW!"
    
    #sudo를 사용하는 각 작업은 입력 및 출력 모두를 보관해야합니다. 로그 파일은 / var / log / sudo / 폴더에 저장해야합니다.
    Defaults	iolog_dir="/var/log/sudo/"
    Defaults	log_input
    Defaults	log_output
    
    #tty모드에서만 sudo를 사용할 수 있게함
    Defaults	requiretty
    
    #sudo를 사용한 인증은 비밀번호가 잘못된 경우 3 번으로 제한되어야합니다.
    Defaults	passwd_tries=3
    ```
    
    - 서브젝트에 적힌대로 /var/log/sudo에 저장하기로 했으니 해당 폴더가 있는지 확인.
    - 없으면 mkdir /var/log/sudo 실행해서 만들어줘야함.
- UFW설치
    - su -
    - apt-get install ufw -y (-y: 설치할때 모두 yes)
    - ufw status verbose (verbose: 자세한 것까지 출력)
    - ufw enable
    - ufw default deny (굳이 해야하나?)
    - ufw allow 4242
    - ufw status verbose
        
        ![스크린샷 2022-03-01 오후 6.51.38.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/dcd43abd-1b91-4d6f-9daa-fc303661ca9d/스크린샷_2022-03-01_오후_6.51.38.png)
        
        (V6) ip길이 4개짜리, 6개짜리 둘다 받음
        
    
    Q. UFW 란?
    
    A. 방화벽
    
- Vim 설치
    - sudo apt-get install vim
- AppArmor 설정
    - apparmor가 기본으로 깔려있지만, 깔려있지 않다면 아래 명령어를 통해 설치
    
    ```bash
    #apparmor설치 확인
    sudo dpkg -l apparmor
    
    #apparmor설치
    sudo apt install apparmor
    
    #apparmor utils 설치
    sudo apt install apparmor-utils
    ```
    
    ```bash
    aa-enabled 명령어를 통해 활성화 여부 확인 
    ```
    
- SSH 설치
    
    ```bash
    su -
    
    apt install openssh-server  #거의 대부분 이미 깔려있음
    
    vim /etc/ssh/sshd_config
    
    Port 22 -> Port 4242 로 변경
    
    #root접근제한 
    PermitRootLogin prohibit-password -> PermitRootLogin no 로 변경
    
    systemctl restart ssh
    
    systemctl status ssh
    ```
    
- 패스워드 정책 설정
    
    ```bash
    su -
    
    vi /etc/login.def 
    #암호는 30 일마다 만료되어야합니다.
    PASS_MAX_DAYS 30
    #비밀번호를 바꾸면 최소 2일은 써야함
    PASS_MIN_DATS 2
    #사용자는 암호가 만료되기 7 일 전에 경고 메시지를 받아야합니다.
    PASS_WARN_AGE 7
    ```
    
    ```bash
    #libpam-pwquality를 설치 해야 아래 설정들을 할 수 있음
    apt-get -y install libpam-pwquality
    
    vi /etc/pam.d/common-password 
    retry=3 뒤로 설정들 쭉 붙일것
    minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username enforce_for_root difok=7
    
    passwd -e <사용자명>
    ```
    
    Q. lcredit=-1 은 왜 해줘야 하지?
    
- monitoring.sh 설정
    
    ```bash
    apt-get -y install sysstat
    vi /root/monitoring.sh
    
    아래 내용 그대로 입력. 틈틈히 저장하고 출력 확인하면서 만들 것.
    
    printf "#Architecture: "
    uname -a 
    # uname: 시스템 정보 출력
    # -a : p와 i 옵션을 제외한 모든 정보 출력
    
    printf "#CPU physical : " # 물리적 프로세서의 수
    cat /proc/cpuinfo | grep "physical id" | wc -l
    # 물리적 프로세서마다 id 번호가 있다.
    
    printf "#vCPU : " # 가상 프로세서의 수
    cat /proc/cpuinfo | grep processor | wc -l
    # 물리프로세서: 코어 수, 가상 프로세서: 쓰레드 수
    
    printf "#Memory Usage: " # 서버에서 현재 사용 가능한 RAM과 사용률
    free --mega | grep Mem | awk '{printf"%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}'
    
    printf "#Disk Usage: " # 서버에서 현재 사용 가능한 메모리 및 사용률
    df -t ext4 —-total -BM | awk '$1=="total"{printf "%d/%dMB (%d%%)\n", $3, $2, $5}'
    
    printf "#CPU load: "
    mpstat | awk '$3=="all"{printf "%.2f%%\n", 100-$13}'
    
    printf "#Last boot: "
    who -b | awk '{printf $3" "$4"\n"}'
    
    printf "#LVM use: "
    if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ] ; then printf "yes\n" ; else printf "no\n" ; fi
    #if문 사용법 : if [ ]; then ; else ; fi
    #else는 생략 가능
    #-gt : greater than. lvm 타입이 하나라도 있으면 yes가 출력된다.
    
    printf "#Connections TCP : "
    ss -t | wc -l | tr -d '\n'
    printf " ESTABLISHED\n"
    
    printf "#User log: "
    who | wc -l
    
    printf "#Network: IP "
    hostname -I | tr -d '\n'
    printf "("
    ip link | awk '$1 == "link/ether" {print $2}' | sed '2, $d' | tr -d '\n'
    printf ")\n"
    
    printf "#Sudo : "
    journalctl _COMM=sudo | grep COMMAND |  wc -l | tr -d '\n'
    printf " cmd\n"
    ```
    
- cron
    
    ```c
    chmod +x monitoring.sh 
    crontab -e
    */10 * * * * /root/monitoring.sh | wall 입력
    ```
    

## 목표

This project aims to introduce you to the wonderful world of virtualization.

## General guidelines (일반 지침)

- The use of VirtualBox (or UTM if you can’t use VirtualBox) is mandatory.
- VirtualBox (또는 VirtualBox를 사용할 수없는 경우 UTM)의 사용은 필수입니다.
- 저장소의 루트에있는 `signature.txt 파일` 만 제출하면됩니다. `시스템 가상 디스크의 서명`을 붙여 넣어야합니다. 자세한 내용은 제출 및 동료 평가로 이동하십시오.

## Mandatory part

이 프로젝트는 특정 규칙에 따라 첫 번째 서버를 설정하는 것으로 구성됩니다.

> 서버 설치의 문제이기 때문에 당신이 최소한의 서비스들을 설치할 것입니다. 그런 이유로 그래픽 인터페이스는 사용할 수 없습니다. [X.org](http://X.org) 또는 이와 동등한 그래픽 서버를 설치하는 것은 금지됩니다. 안그러면 0점입니다!
> 

운영 체제로 Debian의 최신 안정 버전 (테스트 없음 / 불안정) 또는 CentOS의 최신 안정 버전을 선택해야합니다. 시스템 관리가 처음이라면 Debian을 적극 권장합니다.

> CentOS 설정은 매우 복잡합니다. 따라서 KDump를 설정할 필요가 없습니다. 그러나 SELinux는 시작시 실행되어야하며 구성은 프로젝트의 요구에 맞게 조정되어야합니다. Debian 용 AppArmor도 시작시 실행되어야합니다.
> 

`LVM`을 사용하여 암호화 된 `파티션을` `2 개 이상` 만들어야합니다. 다음은 예상되는 분할의 예입니다:

![https://blog.kakaocdn.net/dn/Xlsnk/btq7RLJudr6/D0rQbRokfvkfpWIC7Vtlbk/img.png](https://blog.kakaocdn.net/dn/Xlsnk/btq7RLJudr6/D0rQbRokfvkfpWIC7Vtlbk/img.png)

> 방어하는 동안 선택한 운영 체제에 대해 몇 가지 질문을 받게됩니다. 예를 들어, `aptitude`와 `apt`의 차이점 또는 `SELinux` 또는 `AppArmor`가 무엇인지 알아야합니다. 요컨대, 당신이 사용하는 것을 이해하십시오!
> 

`SSH` 서비스는 `포트 4242`에서만 실행됩니다. 보안상의 이유로 `SSH`를 루트로 사용하여 연결할 수 없어야합니다.

> SSH을 사용하는 것은 새로운 계정을 설정하는 과정에서 평가될 것입니다. 따라서 SSH의 사용방법과 작동원리를 이해하세요!
> 

`UFW 방화벽`으로 운영 체제를 구성하여 `포트 4242 만 열어 두어야합니다.`

> 방화벽은 가상머신이 실행될 때 반드시 활성화되어야 합니다. CentOS의 경우, 기본 방화벽 대신 UFW을 사용해야 합니다. 설치를 위해서는 DNF가 필요할 것입니다.
> 
- 가상 머신의 **hostname**은 42로 끝나는 로그인이어야합니다. (예 : wil42). 평가 중에이 **hostname**을 수정해야합니다.
- 강력한 암호 정책을 구현해야합니다.
- 엄격한 규칙에 따라 **sudo**를 설치하고 구성해야합니다.
- 루트 사용자 외에 사용자 이름(mher)으로 로그인 한 사용자가 있어야합니다.
- 이 사용자(mher)는 user42 및 sudo 그룹에 속해야합니다.

> 평가 중에, 새로운 사용자를 생성해서 그룹에 등록하게 될 것입니다.
> 

## 암호 정책

강력한 암호 정책을 설정하려면 다음 요구 사항을 준수해야합니다.

`/etc/login.defs`

- 암호는 30 일마다 만료되어야합니다.
- 임호는 최소한 2일 후에 수정할 수 있습니다.
- 사용자는 암호가 만료되기 7 일 전에 경고 메시지를 받아야합니다.

`/etc/pam.d/common-password`

- 암호는 10 자 이상이어야합니다.
- 대문자를 1글자 이상 포함해야합니다.
- 숫자를 1글자 이상 포함해야합니다.
- 3 개 이상의 연속 된 동일한 문자를 포함 할 수 없습니다.
- 암호에는 사용자 이름이 포함되지 않아야합니다.
- 암호는 이전 비밀번호와 최소 7글자가 달라야합니다.
: root 비밀번호는 이 규칙이 적용되지 않습니다.
- 물론 root 암호도 이 정책을 준수해야합니다.

> 구성 파일을 설정한 후에는 root 계정을 포함하여 가상 머신에 존재하는 모든 계정의 암호를 변경해야 합니다.
> 

## sudo

sudo 그룹에 대한 강력한 구성을 설정하려면 다음 요구 사항을 준수해야합니다.

- sudo를 사용한 인증은 비밀번호가 잘못된 경우 3 번으로 제한되어야합니다.
- sudo를 사용할 때 잘못된 암호로 인한 오류가 발생하면 선택한 사용자 지정 메시지가 표시되어야합다.
- sudo를 사용하는 각 작업은 입력 및 출력 모두를 보관해야합니다. 로그 파일은 / var / log / sudo / 폴더에 저장해야합니다.
- 보안상의 이유로 `TTY 모드`를 활성화해야합니다.
- 보안상의 이유로 sudo에서 사용할 수있는 경로를 제한해야합니다.
- 예:
    
    ```bash
    /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
    ```
    

## monitoring.sh

마지막으로 `monitoring.sh`라는 간단한 스크립트를 만들어야합니다. bash에서 개발해야합니다.

서버 시작시 스크립트는 10 분마다 모든 터미널에 일부 정보 (아래 나열 됨)를 표시합니다 (벽을보십시오). 배너는 선택 사항입니다. 오류가 표시되지 않아야합니다.

스크립트는 항상 다음 정보를 표시 할 수 있어야합니다.

- 운영체제의 아키텍쳐와 커널 버전
- 물리적 프로세서의 수
- 가상 프로세서의 수
- 서버에서 사용 가능한 현재 RAM과 사용률(%)
- 서버에서 사용 가능한 현재 메모리와 사용률(%)
- 프로세서의 현재 사용률(%)
- 최근 재부팅된 날짜와 시각
- LVM이 활성 상태인지 여부.
- 활성 연결 수
- 서버를 사용하는 사용자 수
- 서버의 IPv4 주소와 해당 MAC(미디어 접근 제어) 주소
- sudo프로그램으로 실행된 명령 수

> 평가 중에, 이 스크립트가 어떻게 동작하는지 설명해야 합니다. 또한 수정하지 않고 중단해야 합니다. cron을 참고하세요
> 

## Cron

다음은 스크립트 작동 방식의 예입니다.

![https://blog.kakaocdn.net/dn/yATQt/btq7Q9qjVvQ/I5WHfKtjkcLW6oDwQkun5K/img.png](https://blog.kakaocdn.net/dn/yATQt/btq7Q9qjVvQ/I5WHfKtjkcLW6oDwQkun5K/img.png)

다음은 주제의 일부 요구 사항을 확인하는 데 사용할 수있는 두 가지 명령입니다.

![https://blog.kakaocdn.net/dn/bB5ryc/btq7RKRoIHq/Ag5oTed4e7ekPai5Z5QvH1/img.png](https://blog.kakaocdn.net/dn/bB5ryc/btq7RKRoIHq/Ag5oTed4e7ekPai5Z5QvH1/img.png)

- Debian
`~# head -n 2 /etc/os-release
/home/[username]# /usr/sbin/aa-status
/home/[username]# ss -tunlp
/home/[username]# /usr/sbin/ufw status`

## 제출 및 동료 평가

Git 저장소의 루트에있는 `signature.txt` 파일 만 제출하면됩니다. 시스템 가상 디스크의 서명을 붙여 넣어야합니다. 이 서명을 받으려면 먼저 기본 설치 폴더 (VM이 저장된 폴더)를 열어야합니다.

- Windows: `%HOMEDRIVE%%HOMEPATH%\VirtualBox VMs\`
- Linux: `~/VirtualBox VMs`
- MacM1: `~/Library/Containers/com.utmapp.UTM/Data/Documents`
- MacOS: `~/VirtualBox VMs/`

그런 다음 `".vdi"파일` (또는 UTM 사용자의 경우 ".qcow2)에서 서명을 검색합니다.sha1 형식의 가상 머신. 다음은 centos_serv.vdi에 대한 4 개의 명령 예입니다.

- Windows: certUtil -hashfile centos_serv.vdi sha1
- Linux: sha1sum centos_serv.vdi
- For Mac M1: shasum Centos.utm/Images/disk-0.qcow2
- MacOS: shasum centos_serv.vdi

다음은 얻을 수있는 출력의 예입니다.

- 6e657c4619944be17df3c31faa030c25e43e40af

> 가상 머신의 서명은 첫 번째 평가 후에 변경 될 수 있습니다. 이 문제를 해결하려면 가상 머신을 복제하거나 저장 상태를 사용할 수 있습니다.
> 

> 물론 Git 저장소에서 가상 머신을 제출하는 것은 금지되어 있습니다. 방어 중에 signature.txt 파일의 서명이 가상 머신의 서명과 비교됩니다. 두 사람이 동일하지 않으면 점수가 0이됩니다.
> 

# 어려웠던점

# 과제후기

# 참고

[born2beroot](https://raidho.tistory.com/45)

[born2beroot 삽질의 흔적](https://tbonelee.tistory.com/m/16)

[[42서울] Born2beroot 설치 및 세팅만 정리](https://techdebt.tistory.com/18?category=833728)

[Born2beRoot with UTM](https://sincerity.page/categories/42Seoul/Born2beRoot/)
