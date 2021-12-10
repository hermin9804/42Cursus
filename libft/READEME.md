# Libft

## 프로젝트 개요

---

libft는 libc에 있는 일부 모듈을 직접 구현하여 [정적라이브러리](https://goodgid.github.io/Static-VS-Dynamic-Libray/) 를 만드는 것이다.
이후 과제에서 libft.a를 사용하는 과제가 있으니 잘 구현 하자.

[노션링크](https://iodized-sailfish-b0c.notion.site/Libft-465972716dbe4e8ebdce69962bc27265)

## 참고자료

---

- size_t 란?
    
    size_t 는 unsigned int 이며, 문자열이나 메모리의 사이즈를 나타낼 때 사용한다. 
    
    "unsigned int"를 typedef unsigned int size_t; 이렇게 size_t 라는 이름으로 정의해 놓은 것이다.
    
    size_t 는, 32비트 운영체제에서는 "부호없는 32비트 정수"이고, 64비트 운영체제에서는 "부호없는 64비트 정수"이다.
    
    그러나 "unsigned int" 또는 "int"는, 64비트 OS라고 해서 꼭 64비트 정수는 아니다.
    
     여전히 32비트일 수도 있디. 이것이 size_t형과 "unsigned int"형의 차이다.
    
    메모리나 문자열 등의 길이를 구할 때에는 "unsigned int" 대신 size_t 라는 형으로 길이가 반환된다.
    
    참고 링크 : [http://mwultong.blogspot.com/2007/06/c-sizet-unsigned-int.html](http://mwultong.blogspot.com/2007/06/c-sizet-unsigned-int.html)
    
- pointer 연산 시 unsigned_char 를 사용하는 이유
    
    GCC에서는 void포인터를 char, unsigned char 크기만큼 연산한다. → 1 byte 씩
    
    포인터는 주솟값 연산이니까 부호를 쓰지 않는다.
    
    char를 쓰지 않고 unsigned char를 쓰는 것이 관례이다.
    
    참고 : [https://dojang.io/mod/page/view.php?id=790](https://dojang.io/mod/page/view.php?id=790)
    
- restrict란?
    
    restrict 포인터는 메모리 접근에 관련된 최적화 기능이다.
    
    restrict 포인터는 각 포인터가 서로 다른 메모리 공간을 가리키고 있고, 다른 곳에서 접근하지 않으니 컴파일러가 최적화를 하라는 뜻!
    
    만약 같은 메모리 공간을 가리키는 포인터에 restrict를 붙여서 컴파일하게 되면 최적화 때문에 잘못된 결과가 나올 수 있으니 주의해야 한다.
    따라서 포인터가 가리키는 메모리 공간을 프로그래머가 직접 확인한 뒤 다른 공간을 가리킬 때만 restrict를 사용해야 한다.
    
     * libft 에서는 restrict 키워드 사용 금지!
    
    `여러분이 재구현하여야 하는 함수들 중 일부는 원본의 프로토타입에 "restrict" 한정자가 사용됩니다. 이 키워드는 c99 표준에 해당하므로, 여러분의 라이브러리 프로토타입들에 이 키워드를 포함시키고 std=c99 플래그를 사용하여 컴파일하는 것은 금지됩니다.`
    
    참고 : [링크](https://dojang.io/mod/page/view.php?id=760)
    
- memcpy 와 memmove의 차이
    - memcpy는 restrict가 붙어있고 memmove는 restrict가 없습니다. 여기서 memmove는 내부적으로 같은 메모리 공간을 가리키는지, 메모리가 겹치는지 모두 확인을 하기 때문에 성능이 떨어집니다. 만약 두 메모리 공간이 다른 공간을 가리키고 겹치지 않는다면 최적화된 memcpy를 사용하여 성능을 향상시킬 수 있습니다.
    - memcpy는 메모리의 내용을 직접 copy하고, memmove는 메모리의 내용을 임시저장소에 저장한 후 복사한다. 따라서 memcpy의 속도는 memmove보다 빠르지만 안정성면에서 떨어진다. memory를 복사할 때 memcpy의 경우에는 자기 자신의 내용을 복사하여 덮어쓸 때, 인접한 메모리에 의해 겹침현상(overlap)이 일어난다.
        
        참고 : [링크](https://blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=sharonichoya&logNo=220510332768#:~:text=memcpy%EB%8A%94%20%EB%A9%94%EB%AA%A8%EB%A6%AC%EC%9D%98%20%EB%82%B4%EC%9A%A9,%EB%8F%99%EC%9E%91%ED%95%98%EB%8A%94%20%EA%B2%83%EC%9D%84%20%EC%9D%98%EB%AF%B8%ED%95%9C%EB%8B%A4.)
        
- strncpy 와 memcpy의 차이
    - strncpy는 복사중 string의 끝인 0x00을 만나면 중지, memcpy는 byte단위로 계산을 해 byte가 끝날 때 까지 계속 복사 할 수 있다.
    - 즉 memcpy는 형에 관계없이 임의의 영역을 지정한 byte 수만큼 복사하는 기능을 수행한다.
    - 둘다 메모리 복사란 점에서는 같은 역할을 하지만 문자값을 비교하여 종료하느냐, **byte 수를 따져 종료하느냐의 차이가 있다.**
    
    참고 : [링크](http://egloos.zum.com/rucaus/v/2366796)
    
- const 와 *(포인터) 위치에 따른 차이
    - 상수 포인터 → cosnt int *ptr = &a;  혹은 int cosnt *ptr = &a;
        
        ```c
        //ptr이 가리키는 주소의 값 변경 불가 
        *ptr = 30; // 오류
        ptr = &b; // 허용
        ```
        
    - 포인터 상수 → int* const ptr = &a;
        
        ```c
        //ptr이 가리키는 주소 변경 불가
        *ptr = 40; // 허용
        ptr = &b; // 오류
        ```
        
    - 상수 포인터 상수 → const int* const ptr =&a;
        
        ```c
        //ptr이 가리키는 주소 && 주소의 값 변경 불가
        *ptr = 50; // 오류
        ptr = &b; // 오류
        ```
        
    
    참고 : [링크](https://coding-chobo.tistory.com/58)
    
- void pointer 란
    
    void 포인터는 일반적인 포인트 변수와는 달리 대상이 되는 데이터의 타입을 명시하지 않은 포인터이다.
    
    따라서 변수, 함수, 포인터 등 어떠한 값도 가리킬 수 있지만, 포인터 연산이나 메모리 참조와 같은 작업은 할 수 없다.
    
    즉 void 포인터는 주소값을 저장하는 것 이외에는 아무것도 할 수 없는 포인터이다.
    
    또한, void 포인터를 사용할 때에는 반드시 먼저 사용하고자 하는 타입으로 명시적 타입 변환 작업을 거친 후에 사용해야 한다.
    
    참고 : [링크](http://tcpschool.com/c/c_pointer_various#:~:text=void%20%ED%8F%AC%EC%9D%B8%ED%84%B0(void%20pointer),%EC%9E%91%EC%97%85%EC%9D%80%20%ED%95%A0%20%EC%88%98%20%EC%97%86%EC%8A%B5%EB%8B%88%EB%8B%A4.)
    

[libft tester](Libft%20989e38c227e0455aada0c8a8b46f1931/libft%20tester%209e19f8e2be4d489d8e79fb9c737ffc19.md)

## part 1

---

- **ft_isalpha**
    - **man**
        - **SYNOPSIS**
            
            ```c
            #include <ctype.h>
            
            int 
            		isalpha(int c);
            ```
            
            - **DESCRIPTION**
            
            The **isalpha**() function tests for any character for which isupper(3) or islower(3) is
            
            true.  The value of the argument must be representable as an unsigned char or the value
            
            of EOF.
            
            In the ASCII character set, this includes the following characters (preceded by their
            
            numeric values, in octal):
            
            - **RETURN** **VALUES**
            
            The **isalpha**() function returns zero if the character tests false and returns non-zero if
            
            the character tests true.
            
    - 함수 설명
        - c 가 알파벳인지 판단 한다.
    - code
        
        ```c
        #include "libft.h"
        
        int	ft_isalpha(int c)
        {
        	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
        }
        ```
        
- **ft_isdigit**
    - **man**
        - **SYNOPSIS**
            
            ```c
            #include <ctype.h>
            
            int
                 isdigit(int c);
            ```
            
            - **DESCRIPTION**
            
            The **isdigit**() function tests for a decimal digit character.  Regardless of locale, this
            
            includes the following characters only:
            
            ``0''         ``1''         ``2''         ``3''         ``4''
            
            ``5''         ``6''         ``7''         ``8''         ``9''
            
            The **isnumber**() function behaves similarly to **isdigit**(), but may recognize additional
            
            characters, depending on the current locale setting.
            
            The value of the argument must be representable as an unsigned char or the value of EOF.
            
            In the ASCII character set, this includes the following characters (preceded by their
            
            numeric values, in octal):
            
            - **RETURN** **VALUES**
            
            The **isdigit**() and **isnumber**() functions return zero if the character tests false and
            
            return non-zero if the character tests true.
            
    - 함수 설명
        - c 가 숫자인지 판단 한다.
    - **code**
        
        숫자면 1 아니면 0 리턴
        
        ```c
        #include "libft.h"
        
        int	ft_isdigit(int c)
        {
        	return ('0' <= c && c <= '9');
        }
        ```
        
- **ft_isalnum**
    - **man**
        - **SYNOPSIS**
            
            ```c
            #include <ctype.h>
            
            int
                 isalnum(int c);
            ```
            
            - **DESCRIPTION**
            
            The **isalnum**() function tests for any character for which isalpha(3) or isdigit(3) is
            
            true.  The value of the argument must be representable as an unsigned char or the value
            
            of EOF.
            
            In the ASCII character set, this includes the following characters (preceded by their
            
            numeric values, in octal):
            
            - **RETURN** **VALUES**
            
            The **isalnum**() function returns zero if the character tests false and returns non-zero if
            
            the character tests true.
            
    - 함수 설명
        - c 가 알파벳 혹은 숫자인지 판단 한다.
    - **code**
        
        알파벳 혹은 숫자면 1 아니면 0 리턴
        
        ```c
        #include "libft.h"
        
        int	ft_isalnum(int c)
        {
        	return (ft_isalpha(c) || ft_isdigit(c));
        }
        ```
        
- **ft_isascii**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <ctype.h>
        
        int
             isascii(int c);
        ```
        
        - **DESCRIPTION**
        
        The **isascii**() function tests for an ASCII character, which is any character between 0
        
        and octal 0177 inclusive.
        
        - **RETURN** **VALUES**
        
        Theisascii() function shall return non-zero ifc is a 7-bit US-
        
        ASCII character code between 0 and octal 0177 inclusive;
        
        otherwise, it shall return 0.
        
    - 함수 설명
        - c 가 아스키코드 인지 판단 한다.
    - **code**
        
        아스키 범위면 1 아니면 0리턴
        
        ```c
        #include "libft.h"
        
        int	ft_isascii(int c)
        {
        	return (0 <= c && c <= 127);
        }
        ```
        
- **ft_isprint**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <ctype.h>
        
        int
             isprint(int c);
        ```
        
        - **DESCRIPTION**
        
        The **isprint**() function tests for any printing character, including space (` ').  The
        
        value of the argument must be representable as an unsigned char or the value of EOF.
        
        In the ASCII character set, this includes the following characters (preceded by their
        
        numeric values, in octal):
        
        - **RETURN** **VALUES**
        
        The **isprint**() function returns zero if the character tests false and returns non-zero if
        
        the character tests true.
        
    - 함수 설명
        - c 가 printable(32 ~ 126) 인지 판단 한다.
    - **code**
        
        ```c
        #include "libft.h"
        
        int	ft_isprint(int c)
        {
        	return (32 <= c && c <= 126);
        }
        ```
        
- **ft_strlen**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
        size_t
             strlen(const char *s);
        ```
        
        - **DESCRIPTION**
        
        The **strlen**() function computes the length of the string s.  The **strnlen**() function
        
        attempts to compute the length of s, but never scans beyond the first maxlen bytes of s.
        
        - **RETURN** **VALUES**
        
        The **strlen**() function returns the number of characters that precede the terminating NUL
        
        character.  The **strnlen**() function returns either the same result as **strlen**() or maxlen,
        
        whichever is smaller.
        
    - 함수 설명
        - 문자열 str 의 길이를 구한다.
    - **code**
        
        문자열의 길이를 리턴
        
        ```c
        #include "libft.h"
        
        size_t	ft_strlen(const char *s)
        {
        	size_t	i;
        
        	i = 0;
        	while (*s)
        	{
        		++i;
        		++s;
        	}
        	return (i);
        }
        ```
        
        size_t는 이론상 가장 큰 사이즈를 담을 수 있는 unsigned 데이터타입이다. 어느 환경에서든 가장큰 unsigned형으로 사용 되기 때문에 안정적으로 사용 할 수 있다.
        
- **ft_memset**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
        void *
             memset(void *b, int c, size_t len);
        ```
        
        - **DESCRIPTION**
        
        The **memset**() function writes len bytes of value c (converted to an unsigned char) to the
        
        string b.
        
        - **RETURN** **VALUES**
        
        The **memset**() function returns its first argument.
        
    - 함수 설명
        - len 만큼 void b의 메모리 블럭으로 접근하여 int c 의 값으로 바꿔준다.
        - 메모리 단위(1 byte)로 접근해야 하기 때문에 unsigned char 로 형 변환 한다.
        - 포인터는 주소값 연산 이기 때문에 char 가 아닌 unsignde char 을 사용 하는 것이 관례이다.
    - **code**
        
        ```c
        #include "libft.h"
        
        void	*ft_memset(void *b, int c, size_t len)
        {
        	unsigned char	*new_b;
        	unsigned char	new_c;
        
        	new_b = (unsigned char *)b;
        	new_c = (unsigned char)c;
        	while (len--)
        		*new_b++ = new_c;
        	return (b);
        }
        ```
        
        - memset 속도 향상1
            
            ```c
            void	*ft_memset(void *b, int c, size_t len)
            {
            	unsigned char	*new_b;
            	long long 		cccc;
            
            	new_b = (unsigned char *)b;
            	cccc = (unsigned char)c;
            	cccc |= cccc << 8;
            	cccc |= cccc << 16;
            	cccc |= cccc << 32;
            	while (len >= 32)
            	{
            		((long long *)new_b)[0] = cccc;
            		((long long *)new_b)[1] = cccc;
            		((long long *)new_b)[2] = cccc;
            		((long long *)new_b)[3] = cccc;
            		new_b += 32;
            		len -= 32;
            	}
            	while (len >= 8)
            	{
            		((long long *)new_b)[0] = cccc;
            		new_b += 8;
            		len -= 8;
            	}
            	while (len--)
            		*new_b++ = (unsigned char)cccc;
            	return (b);
            }
            ```
            
        - memset 속도 향상2
            
            ```c
            #include "libft.h"
            
            unsigned char	*mem16(unsigned char *new_b, long long cccc, size_t *len)
            {
            	while (*len >= 16)
            	{
            		((long long *)new_b)[0] = cccc;
            		((long long *)new_b)[1] = cccc;
            		new_b += 16;
            		*len -= 16;
            	}
            	return (new_b);
            }
            
            unsigned char	*mem32(unsigned char *new_b, long long cccc, size_t *len)
            {
            	while (*len >= 32)
            	{
            		((long long *)new_b)[0] = cccc;
            		((long long *)new_b)[1] = cccc;
            		((long long *)new_b)[2] = cccc;
            		((long long *)new_b)[3] = cccc;
            		new_b += 32;
            		*len -= 32;
            	}
            	return (new_b);
            }
            
            unsigned char	*mem64(unsigned char *new_b, long long cccc, size_t *len)
            {
            	while (*len >= 64)
            	{
            		((long long *)new_b)[0] = cccc;
            		((long long *)new_b)[1] = cccc;
            		((long long *)new_b)[2] = cccc;
            		((long long *)new_b)[3] = cccc;
            		((long long *)new_b)[4] = cccc;
            		((long long *)new_b)[5] = cccc;
            		((long long *)new_b)[6] = cccc;
            		((long long *)new_b)[7] = cccc;
            		new_b += 64;
            		*len -= 64;
            	}
            	return (new_b);
            }
            
            unsigned char	*mem128(unsigned char *new_b, long long cccc, size_t *len)
            {
            	while (*len >= 128)
            	{
            		((long long *)new_b)[0] = cccc;
            		((long long *)new_b)[1] = cccc;
            		((long long *)new_b)[2] = cccc;
            		((long long *)new_b)[3] = cccc;
            		((long long *)new_b)[4] = cccc;
            		((long long *)new_b)[5] = cccc;
            		((long long *)new_b)[6] = cccc;
            		((long long *)new_b)[7] = cccc;
            		((long long *)new_b)[8] = cccc;
            		((long long *)new_b)[9] = cccc;
            		((long long *)new_b)[10] = cccc;
            		((long long *)new_b)[11] = cccc;
            		((long long *)new_b)[12] = cccc;
            		((long long *)new_b)[13] = cccc;
            		((long long *)new_b)[14] = cccc;
            		((long long *)new_b)[15] = cccc;
            		new_b += 128;
            		*len -= 128;
            	}
            	return (new_b);
            }
            
            void	*ft_memset(void *b, int c, size_t len)
            {
            	unsigned char	*new_b;
            	long long		cccc;
            
            	new_b = (unsigned char *)b;
            	cccc = (unsigned char)c;
            	cccc |= cccc << 8;
            	cccc |= cccc << 16;
            	cccc |= cccc << 32;
            	if (len >= 128)
            		new_b = mem128(new_b, cccc, &len);
            	if (len >= 64)
            		new_b = mem64(new_b, cccc, &len);
            	if (len >= 32)
            		new_b = mem32(new_b, cccc, &len);
            	if (len >= 16)
            		new_b = mem16(new_b, cccc, &len);
            	while (len--)
            		*new_b++ = (unsigned char)cccc;
            	return (b);
            }
            ```
            
        
- **ft_bzero**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <strings.h>
        
        void
             bzero(void *s, size_t n);
        ```
        
        - **DESCRIPTION**
        
        The **bzero**() function writes n zeroed bytes to the string s.  If n is zero, **bzero**() does
        
        nothing.
        
        - **RETURN** **VALUES**
        
        none
        
    - 함수 설명
        - dest 부터 size 크기 바이트 만큼 0 으로 채운다.
        - c 언어 비표준이며 deprecated 된 함수 이기 때문에 사용하지 않는 것이 좋다.
    - **code**
        
        void *s의 주소값을 0으로 초기화해준다.
        
        ```c
        #include "libft.h"
        
        void	ft_bzero(void *s, size_t n)
        {
        	ft_memset(s, 0, n);
        }
        ```
        
- **ft_memcpy**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
        void *
             memcpy(void *restrict dst, const void *restrict src, size_t n);
        ```
        
        - **DESCRIPTION**
        
        The **memcpy**() function copies n bytes from memory area src to memory area dst.  If dst
        
        and src overlap, behavior is undefined.  Applications in which dst and src might overlap
        
        should use memmove(3) instead.
        
        - **RETURN** **VALUES**
        
        The **memcpy**() function returns the original value of dst.
        
    - 함수 설명
        - src 가 기키는 곳 부터 n 바이트 만큼 dest 에 복사한다.
    - **code**
        
        ```c
        #include "libft.h"
        
        void	*ft_memcpy(void *dst, const void *src, size_t n)
        {
        	unsigned char	*new_dst;
        	unsigned char	*new_src;
        
        	new_dst = (unsigned char *)dst;
        	new_src = (unsigned char *)src;
        	if (dst == src)
        		return (dst);
        	while (n--)
        		*new_dst++ = *new_src++;
        	return (dst);
        
        ```
        
- **ft_memmove**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
             void *
             memmove(void *dst, const void *src, size_t len);
        ```
        
        - **DESCRIPTION**
        
        The **memmove**() function copies len bytes from string src to string dst.  The two strings may overlap; the
        
        copy is always done in a non-destructive manner.
        
        - **RETURN** **VALUES**
        
        The **memmove**() function returns the original value of dst.
        
    - 함수 설명
        - dst 에 src 를 복사한다.
        - dst > src 인 경우 overlap 을 방지 하기위해 거꾸로 복사한다
    - **code**
        
        ```c
        #include "libft.h"
        
        void	*ft_memmove(void *dst, const void *src, size_t len)
        {
        	unsigned char	*new_dst;
        	unsigned char	*new_src;
        
        	new_dst = (unsigned char *)dst;
        	new_src = (unsigned char *)src;
        	if (dst == src || len == 0)
        		return (dst);
        	if (dst < src)
        		while (len--)
        			*new_dst++ = *new_src++;
        	else
        		while (len--)
        			*(new_dst + len) = *(new_src + len);
        	return (dst);
        }
        ```
        
- **ft_strlcpy**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
             size_t
             strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
        
             size_t
             strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
        ```
        
        - **DESCRIPTION**
        
        The **strlcpy**() and **strlcat**() functions copy and concatenate strings with the same input parameters and output
        
        result as snprintf(3).  They are designed to be safer, more consistent, and less error prone replacements
        
        for the easily misused functions strncpy(3) and strncat(3).
        
        **strlcpy**() and **strlcat**() take the full size of the destination buffer and guarantee NUL-termination if there
        
        is room.  Note that room for the NUL should be included in dstsize.
        
        **strlcpy**() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if
        
        dstsize is not 0.**strlcat**() appends string src to the end of dst.  It will append at most dstsize - strlen(dst) - 1 charac-
        
        ters.  It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize
        
        (in practice this should not happen as it means that either dstsize is incorrect or that dst is not a proper
        
        string).
        
        If the src and dst strings overlap, the behavior is undefined.
        
        - **RETURN** **VALUES**
        
        Besides quibbles over the return type (size_t versus int) and signal handler safety (snprintf(3) is not
        
        entirely safe on some systems), the following two are equivalent:
        
        n = strlcpy(dst, src, len);
        
        n = snprintf(dst, len, "%s", src);
        
        Like snprintf(3), the **strlcpy**() and **strlcat**() functions return the total length of the string they tried to
        
        create.  For **strlcpy**() that means the length of src.  For **strlcat**() that means the initial length of dst
        
        plus the length of src.
        
        If the return value is **>=** dstsize, the output string has been truncated.  It is the caller's responsibility
        
        to handle this.
        
    - 함수 설명
        - dest에 src를 destsize만큼 복사, destsize == 0 이면 src_len을 리턴
        - destsize 가 0 이 아닌 경우 destsize - 1 까지 복사하고  마지막에 NULL 문자를 삽입한다.
        - strlcpy 는 마지막 NULL 문자 삽입을 보장하기 때문에 strncpy 보다 오류가 적다.
        - strncpy 는 마지막 NULL 문자 삽입을 보장하니 않는다.
    - **code**
        
        ```c
        #include "libft.h"
        
        size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
        {
        	size_t	i;
        	size_t	src_len;
        
        	i = 0;
        	src_len = ft_strlen(src);
        	if (destsize == 0)
        		return (src_len);
        	while (src[i] && i < (destsize - 1))
        	{
        		dest[i] = src[i];
        		++i;
        	}
        	dest[i] = 0;
        	return (src_len);
        }
        ```
        
- **ft_strlcat**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
             size_t
             strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
        
             size_t
             strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
        ```
        
        - **DESCRIPTION**
        
        The **strlcpy**() and **strlcat**() functions copy and concatenate strings with the same input parameters and output
        
        result as snprintf(3).  They are designed to be safer, more consistent, and less error prone replacements
        
        for the easily misused functions strncpy(3) and strncat(3).
        
        **strlcpy**() and **strlcat**() take the full size of the destination buffer and guarantee NUL-termination if there
        
        is room.  Note that room for the NUL should be included in dstsize.
        
        **strlcpy**() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if
        
        dstsize is not 0.
        
        **strlcat**() appends string src to the end of dst.  It will append at most dstsize - strlen(dst) - 1 charac-
        
        ters.  It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize
        
        (in practice this should not happen as it means that either dstsize is incorrect or that dst is not a proper
        
        string).
        
        If the src and dst strings overlap, the behavior is undefined.
        
        - **RETURN** **VALUES**
        
        Besides quibbles over the return type (size_t versus int) and signal handler safety (snprintf(3) is not
        
        entirely safe on some systems), the following two are equivalent:
        
        n = strlcpy(dst, src, len);
        
        n = snprintf(dst, len, "%s", src);
        
        Like snprintf(3), the **strlcpy**() and **strlcat**() functions return the total length of the string they tried to
        
        create.  For **strlcpy**() that means the length of src.  For **strlcat**() that means the initial length of dst
        
        plus the length of src.
        
        If the return value is **>=** dstsize, the output string has been truncated.  It is the caller's responsibility
        
        to handle this.
        
    - 함수 설명
        - strlcat은 src를 dst의 끝에 추가해주는 함수이다.
        - dst 의 마지막 위치에 src 을 dstsize - strlen(dst) - 1 만큼 복사하고 (-1을 해주는 이유는 더 안전한 함수로 사용하기 위해), 끝에 널문자를 삽입한다.
        
        여기서 dstsize는 버퍼의 크기이고 size와 dst의 크기에 따라 반환값이 달라지게 된다.
        
        - dstsize가 dst의 크기보다 작을 때, strlen(src) + dstsize 를 반환한다.
        - dstsize가 dst의 크기보다 클 때, strlen(src) + strlen(dst)를 반환한다.
        - dst 의 마지막 위치에 src 을 dstsize - strlen(dst) - 1 만큼 복사하고 (-1을 해주는 이유는 더 안전한 함수로 사용하기 위해), 끝에 널문자를 삽입한다.
    - **code**
        
        ```c
        #include "libft.h"
        
        size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
        {
        	size_t	i;
        
        	i = 0;
        	while (*dst && i < dstsize) // dstsize < dstlength 인경우 i 는 dstsize - 1
        	{
        		++i;
        		++dst;
        	}
        	while (*src && i + 1 < dstsize)
        	{
        		*dst = *src;
        		++dst;
        		++src;
        		++i;
        	}
        	if (i < dstsize)
        		*dst = 0;
        	while (*src)
        	{
        		++i;
        		++src;
        	}
        	return (i);
        }
        ```
        
- **ft_toupper**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <ctype.h>
        
             int
             toupper(int c);
        
             #include <ctype.h>
             #include <xlocale.h>
        
             int
             toupper_l(int c, locale_t loc);
        ```
        
        - **DESCRIPTION**
        
        The **toupper**() function converts a lower-case letter to the corresponding upper-case letter.  The argument
        
        must be representable as an unsigned char or the value of EOF.
        
        Although the **toupper**() function uses the current locale, the **toupper_l**() function may be passed a locale
        
        directly. See xlocale(3) for more information.
        
        - **RETURN** **VALUES**
        
        If the argument is a lower-case letter, the **toupper**() function returns the corresponding upper-case letter
        
        if there is one; otherwise, the argument is returned unchanged.
        
    - 함수 설명
        - c 가 소문자라면 대문자로 변경한다.
    - **code**
        
        ```c
        #include "libft.h"
        
        int	ft_toupper(int c)
        {
        	if ('a' <= c && c <= 'z')
        		return (c - 'a' + 'A');
        	return (c);
        }
        ```
        
- **ft_tolower**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <ctype.h>
        
             int
             tolower(int c);
        
             #include <ctype.h>
             #include <xlocale.h>
        
             int
             tolower_l(int c, locale_t loc);
        ```
        
        - **DESCRIPTION**
        
        The **tolower**() function converts an upper-case letter to the corresponding lower-case letter.  The argument
        
        must be representable as an unsigned char or the value of EOF.
        
        Although the **tolower**() function uses the current locale, the **tolower_l**() function may be passed a locale
        
        directly. See xlocale(3) for more information.
        
        - **RETURN** **VALUES**
        
        If the argument is an upper-case letter, the **tolower**() function returns the corresponding lower-case letter
        
        if there is one; otherwise, the argument is returned unchanged.
        
    - 함수 설명
        - c 가 대문자라면 소문자로 변경한다.
    - **code**
        
        ```c
        #include "libft.h"
        
        int	ft_tolower(int c)
        {
        	if ('A' <= c && c <= 'Z')
        		return (c - 'A' + 'a');
        	return (c);
        }
        ```
        
- **ft_strchr**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
             char *
             strchr(const char *s, int c);
        
             char *
             strrchr(const char *s, int c);
        ```
        
        - **DESCRIPTION**
        
        The **strchr**() function locates the first occurrence of c (converted to a char) in the string pointed to by s.
        
        The terminating null character is considered to be part of the string; therefore if c is `\0', the functions
        
        locate the terminating `\0'.
        
        The **strrchr**() function is identical to **strchr**(), except it locates the last occurrence of c.
        
        - **RETURN** **VALUES**
        
        The functions **strchr**() and **strrchr**() return a pointer to the located character, or NULL if the character
        
        does not appear in the string.
        
    - 함수 설명
        - s에서 처음찾은 c의 주소를 리턴
        - c가 0 인경우에도 NULL 문자의 위치를 찾으면 그 주소를 리턴
    - **code**
        
        ```c
        #include "libft.h"
        
        char	*ft_strchr(const char *s, int c)
        {
        	while (*s)
        	{
        		if (*s == (char)c)
        			return ((char *)s);
        		++s;
        	}
        	if (*s == (char)c)//c가 0인경우 그 주소 리턴
        		return ((char *)s);
        	return (0);
        }
        
        ```
        
- **ft_strrchr**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
             char *
             strchr(const char *s, int c);
        
             char *
             strrchr(const char *s, int c);
        ```
        
        - **DESCRIPTION**
        
        The **strchr**() function locates the first occurrence of c (converted to a char) in the string pointed to by s.
        
        The terminating null character is considered to be part of the string; therefore if c is `\0', the functions
        
        locate the terminating `\0'.
        
        The **strrchr**() function is identical to **strchr**(), except it locates the last occurrence of c.
        
        - **RETURN** **VALUES**
        
        The functions **strchr**() and **strrchr**() return a pointer to the located character, or NULL if the character
        
        does not appear in the string.
        
    - 함수 설명
        - s에서 마지막에 찾은 c의 주소를 리턴
        - c가 0 인경우에도 NULL 문자의 위치를 찾으면 그 주소를 리턴
    - **code**
        
        ```c
        #include "libft.h"
        
        char	*ft_strrchr(const char *s, int c)
        {
        	char	*ret;
        
        	ret = 0;
        	while (*s)
        	{
        		if (*s == (char)c)
        			ret = (char *)s; //찾은 c의 주소를 저장하고 뒤에 c가 또 있는지 검색
        		++s;
        	}
        	if (*s == (char)c) //c가 0인경우 그 주소 리턴
        		ret = (char *)s;
        	return (ret);
        }
        ```
        
- **ft_strncmp**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
             int
             strcmp(const char *s1, const char *s2);
        
             int
             strncmp(const char *s1, const char *s2, size_t n);
        ```
        
        - **DESCRIPTION**
        
        The **strcmp**() and **strncmp**() functions lexicographically compare the null-terminated strings s1 and s2.
        
        The **strncmp**() function compares not more than n characters.  Because **strncmp**() is designed for comparing
        
        strings rather than binary data, characters that appear after a `\0' character are not compared.
        
        - **RETURN** **VALUES**
        
        The **strcmp**() and **strncmp**() functions return an integer greater than, equal to, or less than 0, according as
        
        the string s1 is greater than, equal to, or less than the string s2.  The comparison is done using unsigned
        
        characters, so that `\200' is greater than `\0'.
        
    - 함수 설명
        - size n만큼 s1 과 s2를 비교한다. 차이가 발생 하면 s1 - s2를 리턴 한다.
        - unsigned char 을 사용 하는 이유 char 범위를 넘어가는 경우(ex \200, \0) 원하지 않는 값이 나온다.
    - **code**
        
        ```c
        #include "libft.h"
        
        int	ft_strncmp(const char *s1, const char *s2, size_t n)
        {
        	unsigned char	*t1;
        	unsigned char	*t2;
        
        	t1 = (unsigned char *)s1;
        	t2 = (unsigned char *)s2;
        	while (n-- > 0)
        	{
        		if (*t1 != *t2 || !*t1 || !*t2)
        			return (*t1 - *t2);
        		++t1;
        		++t2;
        	}
        	return (0);
        }
        ```
        
- **ft_memchr**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
             void *
             memchr(const void *s, int c, size_t n);
        ```
        
        - **DESCRIPTION**
        
        The **memchr**() function locates the first occurrence of c (converted to an unsigned char) in string s.
        
        - **RETURN** **VALUES**
        
        The **memchr**() function returns a pointer to the byte located, or NULL if no such byte exists within n bytes.
        
    - 함수 설명
        - s에서 c를 n만큼 검색후 찾은 주소 리턴, 못찾으면 0리턴
    - **code**
        
        ```c
        #include "libft.h"
        
        void	*ft_memchr(const void *s, int c, size_t n)
        {
        	while (n--)
        	{
        		if (*(unsigned char *)s == (unsigned char)c)
        			return ((void *)s);
        		++s;
        	}
        	return (0);
        }
        ```
        
- **ft_memcmp**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
             int
             memcmp(const void *s1, const void *s2, size_t n);
        ```
        
        - **DESCRIPTION**
        
        he **memcmp**() function compares byte string s1 against byte string s2.  Both strings
        
        are assumed to be n bytes long.
        
        - **RETURN** **VALUES**
        
        The **memcmp**() function returns zero if the two strings are identical, otherwise
        
        returns the difference between the first two differing bytes (treated as unsigned
        
        char values, so that `\200' is greater than `\0', for example).  Zero-length strings
        
        are always identical.  This behavior is not required by C and portable code should
        
        only depend on the sign of the returned value.
        
    - 함수 설명
        - size n만큼 s1 과 s2를 비교한다. 차이가 발생 하면 s1 - s2를 리턴한다.
    - **code**
        
        ```c
        #include "libft.h"
        
        void	*ft_memcmp(const void *s, const char *s2, size_t n)
        {
        	unsigned char *new_s1;
        	unsigned char *new_s2;
        
        	new_s1 = (unsigned char *)s1;
        	new_s2 = (unsigned char *)s2;
        	whiel (n--)
        	{
        		if (*new_s1 != *new_s2)
        			return (*new_s1 - *new_s2);
        		++new_s1;
        		++new_s2;
        	}
        	return (0);	
        }
        ```
        
- **ft_strnstr**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
             char *
             strstr(const char *haystack, const char *needle);
        
             char *
             strcasestr(const char *haystack, const char *needle);
        
             char *
             strnstr(const char *haystack, const char *needle, size_t len);
        
             #include <string.h>
             #include <xlocale.h>
        
             char *
             strcasestr_l(const char *haystack, const char *needle, locale_t loc);
        ```
        
        - **DESCRIPTION**
        
        The **strstr**() function locates the first occurrence of the null-terminated string needle in the null-termi-
        
        nated string haystack.
        
        The **strcasestr**() function is similar to **strstr**(), but ignores the case of both strings.
        
        The **strnstr**() function locates the first occurrence of the null-terminated string needle in the string
        
        haystack, where not more than len characters are searched.  Characters that appear after a `\0' character
        
        are not searched.  Since the **strnstr**() function is a FreeBSD specific API, it should only be used when
        
        portability is not a concern.
        
        While the **strcasestr**() function uses the current locale, the **strcasestr_l**() function may be passed a locale
        
        directly. See xlocale(3) for more information.
        
        - **RETURN** **VALUES**
        
        If needle is an empty string, haystack is returned; if needle occurs nowhere in haystack, NULL is returned;
        otherwise a pointer to the first character of the first occurrence of needle is returned.
        
    - 함수 설명
        - len만큼 검사를 하며 haystack에서 needle이 나올 때 까지 검사를 하고, 만약 full needle이 나온다면 그 위치의 주소를 리턴한다.
    - **code**
        
        ```c
        #include "libft.h"
        
        char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
        {
        	size_t	h_len;
        	size_t	n_len;
        	size_t	size;
        
        	if (!*needle)
        		return ((char *)haystack); //needle가 null인경우 haystack을 리턴
        	h_len = ft_strlen(haystack);
        	n_len = ft_strlen(needle);
        	if (h_len < n_len || len < n_len) //인 경우 어차피 못찾으니 0리턴
        		return (0);
        	if (h_len > len)
        		size = len;
        	else
        		size = h_len; // h_len <= len일때 len 만큼 검색하면 더 큰 범위를 검색하기 때문에
        									// size를 다시 정의
        	while (size-- >= n_len)
        	{
        		if (ft_memcmp(haystack, needle, n_len) == 0)
        			return ((char *)haystack);
        		++haystack;
        	}
        	return (0);
        }
        ```
        
- **ft_atoi**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <stdlib.h>
        
             int
             atoi(const char *str);
        
             #include <xlocale.h>
        
             int
             atoi_l(const char *str, locale_t loc);
        ```
        
        - **DESCRIPTION**
        
        The **atoi**() function converts the initial portion of the string pointed to by str to int representation.
        
        It is equivalent to:
        
        (int)strtol(str, (char **)NULL, 10);
        
        While the **atoi**() function uses the current locale, the **atoi_l**() function may be passed a locale directly.
        
        See xlocale(3) for more information.
        
        - **RETURN** **VALUES**
        
        The **atoi**() and **atoi_l**() functions are thread-safe and async-cancel-safe.
        
        The **strtol**() and **strtol_l**() functions are recommended instead of **atoi**() and **atoi_l**() functions, especially
        
        in new code.
        
    - 함수 설명
        - const char 형의 배열을 받아 숫자로 바꿔주는 함수이다.
        - 처음에는 whitespace 가 올 수 있으며, 그 후에는 부호 하나만 올 수 있다.
        - 그 외에는 숫자만 인식하며, 숫자가 아닌 다른 문자가 온다면 이때까지 읽은 곳 까지 리턴한다.
    - **code**
        
        ```c
        #include "libft.h"
        
        int	ft_atoi(const char *str)
        {
        	long	ret;
        	int		sign;
        
        	ret = 0;
        	sign = 1;
        	while (*str == ' ' || (9 <= *str && *str <= 13))
        		++str;
        	if (*str == '+' || *str == '-')
        		if (*str++ == '-')
        			sign *= -1;
        	while ('0' <= *str && *str <= '9')
        	{
        		ret = ret * 10 + (*str++ - '0');
        		if (ret < 0)
        			return ((sign + 1) / -2);
        	}
        	return (sign * ret);
        }
        ```
        
        - atoi long max 부가 설명
            
            long 으로 받은 이유 atoi는 long max이상 값이 들어 왔을 때 내부적으로 strtol을 호출해서 처리한다.
            
            long max 이상 값이 들어온 경우 부호에 따라 0, -1 을 리턴한다.
            sign = 1 인경우 -1을 리턴
            sign = -1 인경우 0 을 리턴 
            
            - 오버플로우 발생 시 → long long sign 바뀜 (+ → -)
            - sign + 1) / -2한 이유 1 → -1, -1 → 0 이 되야함
            - long result라고 써야하지 않을까? int형은 운영체제에 따라 2B~4B로 설정되고, long형은 4B ~ 8B로 한다. 하지만 Win64에서는 long도 4B로 설정된다. atoi는 strtol과 동일하게 동작하니까 long형을 사용하는게 맞는 것 같다. 테스트는 맥64 환경에서 실시해서 long / long long의 차이가 없긴하다.
                
                애초에 libc의 atoi도 window와 linux에서의 오버플로우 동작이 다르다. linux환경에서는 long result와 long long result가 같아서 문제가 없지만, window환경에서는 long result 사용시 4B 표현범위 이상을 모두 overflow처리가 된다. (ft_atoi) 또한 atoi가 window환경에서는 LONG_LONG_MAX를 넘는 overflow에 대해서 따로 처리를 하지 않는다. 따라서 문제 의도에 맞게, long형을 사용한다.
                
                요약 및 결론 window64에서는 어짜피 atoi랑 비교했을때, 둘중에 뭘 쓰던 둘다 다르게 나온다. linux or mac에서는 32 / 64에 따라서 long의 차이가 있으므로, long으로 하는게 맞는 것 같다.
                
            - "result < 0"이랑 "sign + 1 / -2"는 무엇인가요? 2의 보수법을 이용하는 컴퓨터에서 msb는 숫자의 부호를 의미한다. 2bit 숫자표현에서 -2 -1 0 1 으로 총 4개의 숫자를 표현할 수 있다. 각각의 숫자는 이진수로 10 11 00 01이다. 즉 양수이던 result에 양수를 더해서 음수가 된다는 것은 overflow가 발생했다는 것을 알 수 있다. (여기서는 long형 크기 이상) 그때, man에서는 양수였다면 LONG_MAX, 음수였다면 LONG_MIN을 반환한다고 되어있다. 따라서 양수였다면 0xffff... 즉 제일 앞 sign bit가 1이고, 모든 bit가 1인 -1을 반환하고, 음수였다면 0x0000... 즉 0을 반환한다. 우리는 sign 변수를 통해서 기존 부호를 알고있다. 따라서 overflow발생 시 sign을 이용하여 -1이면 0, 1이면 -1을 반환하도록 작성한 것이다.
            - atoi long max test
                
                ```c
                #include <stdio.h>
                #include "libft.h"
                int main(void)
                {
                    printf("a int max 2147483647 : %d\n", atoi("2147483647"));
                    printf("f int max 2147483647 : %d\n", ft_atoi("2147483647"));
                    printf("a int min -2147483648 : %d\n", atoi("-2147483648"));
                    printf("f int min -2147483648 : %d\n", ft_atoi("-2147483648"));
                    printf("a int over 9999999999 : %d\n", atoi("9999999999"));
                    printf("f int over 9999999999 : %d\n", ft_atoi("9999999999"));
                    printf("a int under -9999999999 : %d\n", atoi("-9999999999"));
                    printf("f int under -9999999999 : %d\n", ft_atoi("-9999999999"));
                    printf("a long long plus 92233720368547758 : %d\n", atoi("92233720368547758"));
                    printf("f long long plus 92233720368547758 : %d\n", ft_atoi("92233720368547758"));
                    printf("a long long minus -92233720368547758 : %d\n", atoi("-92233720368547758"));
                    printf("f long long minus -92233720368547758 : %d\n", ft_atoi("-92233720368547758"));
                    printf("a long long max 9223372036854775807 : %d\n", atoi("9223372036854775807"));
                    printf("f long long max 9223372036854775807 : %d\n", ft_atoi("9223372036854775807"));
                    printf("a long long min -9223372036854775808 : %d\n", atoi("–9223372036854775808"));
                    printf("f long long min -9223372036854775808 : %d\n", ft_atoi("–9223372036854775808"));
                    printf("a long long max / 10 922337203685477580 : %d\n", atoi("922337203685477580"));
                    printf("f long long max / 10 922337203685477580 : %d\n", ft_atoi("922337203685477580"));
                    printf("a long long max / 10 + 1 922337203685477581 : %d\n", atoi("922337203685477581"));
                    printf("f long long max / 10 + 1 922337203685477581 : %d\n", ft_atoi("922337203685477581"));
                    printf("a long long max / 10 + 4 922337203685477584 : %d\n", atoi("922337203685477584"));
                    printf("f long long max / 10 + 4 922337203685477584 : %d\n", ft_atoi("922337203685477584"));
                    printf("a long long max / 10 + 5 922337203685477585 : %d\n", atoi("922337203685477585"));
                    printf("f long long max / 10 + 5 922337203685477585 : %d\n", ft_atoi("922337203685477585"));
                    printf("a long long max - 1 922337203685477586 : %d\n", atoi("922337203685477586"));
                    printf("f long long max - 1 922337203685477586 : %d\n", ft_atoi("922337203685477586"));
                    printf("a long long max + 1 9223372036854775808 : %d\n", atoi("9223372036854775808"));
                    printf("f long long max + 1 9223372036854775808 : %d\n", ft_atoi("9223372036854775808"));
                    printf("a long long max + 2 9223372036854775809 : %d\n", atoi("9223372036854775809"));
                    printf("f long long max + 2 9223372036854775809 : %d\n", ft_atoi("9223372036854775809"));
                    printf("a long long max + 10 9223372036854775817 : %d\n", atoi("9223372036854775817"));
                    printf("f long long max + 10 9223372036854775817 : %d\n", ft_atoi("9223372036854775817"));
                    printf("a long long min - 1 –9223372036854775809 : %d\n", atoi("–9223372036854775809"));
                    printf("f long long min - 1 –9223372036854775809 : %d\n", ft_atoi("–9223372036854775809"));
                    printf("a long long min - 2 –9223372036854775810 : %d\n", atoi("–9223372036854775810"));
                    printf("f long long min - 2 –9223372036854775810 : %d\n", ft_atoi("–9223372036854775810"));
                    printf("a long long min - 10 –9223372036854775818 : %d\n", atoi("–9223372036854775818"));
                    printf("f long long min - 10 –9223372036854775818 : %d\n", ft_atoi("–9223372036854775818"));
                    printf("a long long over 9223379876854775807 : %d\n", atoi("9223379876854775807"));
                    printf("f long long over 9223379876854775807 : %d\n", ft_atoi("9223379876854775807"));
                    printf("a long long under -9223379876854775807 : %d\n", atoi("-9223379876854775807"));
                    printf("f long long under -9223379876854775807 : %d\n", ft_atoi("-9223379876854775807"));
                    printf("a long long half 4611686018427387903 : %d\n", atoi("4611686018427387903"));
                    printf("f long long half 4611686018427387903 : %d\n", ft_atoi("4611686018427387903"));
                    printf("a zero 0 : %d\n", atoi("0"));
                    printf("f zero 0 : %d\n", ft_atoi("0"));
                    printf("a empty  : %d\n", atoi(""));
                    printf("f empty  : %d\n", ft_atoi(""));
                    return (0);
                }
                ```
                
- **ft_calloc**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <stdlib.h>
        
             void *
             calloc(size_t count, size_t size);
        
             void
             free(void *ptr);
        
             void *
             malloc(size_t size);
        
             void *
             realloc(void *ptr, size_t size);
        
             void *
             reallocf(void *ptr, size_t size);
        
             void *
             valloc(size_t size);
        
             void *
             aligned_alloc(size_t alignment, size_t size);†
        ```
        
        - **DESCRIPTION**
        
        The **malloc**(), **calloc**(), **valloc**(), **realloc**(), and **reallocf**() functions allocate memory.  The allo-
        
        cated memory is aligned such that it can be used for any data type, including AltiVec- and SSE-
        
        related types.  The **aligned_alloc**() function allocates memory with the requested alignment.  The
        
        **free**() function frees allocations that were created via the preceding allocation functions.
        
        The **malloc**() function allocates size bytes of memory and returns a pointer to the allocated mem-
        
        ory.
        
        The **calloc**() function contiguously allocates enough space for count objects that are size bytes
        
        of memory each and returns a pointer to the allocated memory.  The allocated memory is filled
        
        with bytes of value zero.
        
        The **valloc**() function allocates size bytes of memory and returns a pointer to the allocated mem-
        
        ory.  The allocated memory is aligned on a page boundary.
        
        The **aligned_alloc**() function allocates size bytes of memory with an alignment specified by
        
        alignment and returns a pointer to the allocated memory.
        
        The **realloc**() function tries to change the size of the allocation pointed to by ptr to size, and
        
        returns ptr.  If there is not enough room to enlarge the memory allocation pointed to by ptr,
        
        **realloc**() creates a new allocation, copies as much of the old data pointed to by ptr as will fit
        
        to the new allocation, frees the old allocation, and returns a pointer to the allocated memory.
        
        If ptr is NULL, **realloc**() is identical to a call to **malloc**() for size bytes.  If size is zero and
        
        ptr is not NULL, a new, minimum sized object is allocated and the original object is freed.  When
        
        extending a region allocated with calloc(3), realloc(3) does not guarantee that the additional
        
        memory is also zero-filled.
        
        The **reallocf**() function is identical to the **realloc**() function, except that it will free the
        
        passed pointer when the requested memory cannot be allocated.  This is a FreeBSD specific API
        
        designed to ease the problems with traditional coding styles for realloc causing memory leaks in
        
        libraries.
        
        The **free**() function deallocates the memory allocation pointed to by ptr. If ptr is a NULL
        
        pointer, no operation is performed.
        
        - **RETURN** **VALUES**
        
        If successful, **calloc**(), **malloc**(), **realloc**(), **reallocf**(), **valloc**(), and **aligned_alloc**() functions
        
        return a pointer to allocated memory.  If there is an error, they return a NULL pointer and set
        
        errno to ENOMEM.
        
        In addition, **aligned_alloc**() returns a NULL pointer and sets errno to EINVAL if size is not an
        
        integral multiple of alignment, or if alignment is not a power of 2 at least as large as
        
        **sizeof**(void *).
        
        For **realloc**(), the input pointer is still valid if reallocation failed.  For **reallocf**(), the
        
        input pointer will have been freed if reallocation failed.
        
        The **free**() function does not return a value.
        
    - 함수 설명
        - size*count 만큼의 공간을 확보 후 메모리를 비우고 그 주소값을 전달해준다
    - **code**
        
        ```c
        #include "libft.h"
        
        void	*ft_calloc(size_t count, size_t size)
        {
        	void	*ret;
        
        	ret = (void *)malloc(count * size);
        	if (!ret)
        		return (0);
        	ft_bzero(ret, (count * size));
        	return (ret);
        }
        ```
        
- **ft_strdup**
    - **man**
        - **SYNOPSIS**
        
        ```c
        #include <string.h>
        
             char *
             strdup(const char *s1);
        
             char *
             strndup(const char *s1, size_t n);
        ```
        
        - **DESCRIPTION**
        
        The **strdup**() function allocates sufficient memory for a copy of the string s1, does the copy, and
        
        returns a pointer to it.  The pointer may subsequently be used as an argument to the function
        
        free(3).
        
        If insufficient memory is available, NULL is returned and errno is set to ENOMEM.
        
        The **strndup**() function copies at most n characters from the string s1 always NUL terminating the
        
        copied string.
        
        - **RETURN** **VALUES**
    - 함수 설명
        - s1과 동일한 배열을 생성 후 생성한 배열의 주소를 리턴한다.
    - **code**
        
        ```c
        #include "libft.h"
        
        char	*ft_strdup(const char *s1)
        {
        	size_t	len;
        	char	*ret;
        	char	*tmp;
        
        	len = ft_strlen(s1);
        	ret = (char *)malloc(sizeof(char) * (len + 1));
        	if (!ret)
        		return (0);
        	tmp = ret;
        	while (len--)
        	{
        		*tmp = *s1;
        		++tmp;
        		++s1;
        	}
        	*tmp = 0;
        	return (ret);
        }
        ```
        
        s1 == null 일때
        
        ft_strdup → segmentation fault
        
        strdup → segmentation fault
        

## part 2

---

- **ft_substr**
    - 함수 설명
        - Prototype
        
        ```c
        char *ft_strjoin(char const *s1, char const *s2);
        ```
        
        - **Description**
        
        Allocates (with malloc(3)) and returns a substring from the string ’s’.
        
        The substring begins at index ’start’ and is of maximum size ’len’.
        
        - **Return value**
        
        The substring. NULL if the allocation fails.
        
    - **code**
        
        len + 1크기만큼의 배열을 할당하여 그 안에 s배열의 start index부터 넣기 시작해서 len크기 까지 혹은 s가 끝날 때 까지 삽입 후 마지막에 null 삽입 후 리턴한다.
        
        ```c
        #include "libft.h"
        
        char	*ft_substr(char const *s, unsigned int start, size_t len)
        {
        	char	*substr;
        	size_t	tmp_len;
        
        	if (!s)
        		return (0);
        	if ((unsigned int)ft_strlen(s) < start)
        		return (ft_strdup(""));
        	tmp_len = ft_strlen(s + start);
        	if (tmp_len < len) //s의 끝 까지만 비교하기 위함
        		len = tmp_len;
        	substr = (char *)malloc(sizeof(char) * (len + 1));
        	if (!substr)
        		return (0);
        	ft_strlcpy(substr, s + start, len + 1);
        	return (substr);
        }
        ```
        
- **ft_strjoin**
    - 함수 설명
        - Prototype
        
        ```c
        char *ft_strjoin(char const *s1, char const *s2);
        ```
        
        - **Description**
        
        Allocates (with malloc(3)) and returns a new
        string, which is the result of the concatenation
        of ’s1’ and ’s2’.
        
        - **Return value**
        
        The new string. NULL if the allocation fails.
        
    - **code**
        
        s1과 s2를 받으며 그 둘을 합친 결과를 새로운 배열을 동적할당하여 리턴
        
        ```c
        #include "libft.h"
        
        char	*ft_strjoin(char const *s1, char const *s2)
        {
        	char	*ret;
        	size_t	s1_len;
        	size_t	s2_len;
        
        	if (!s1 && !s2)
        		return (0);
        	else if (!s1)
        		return (ft_strdup(s2));
        	else if (!s2)
        		return (ft_strdup(s1));
        	s1_len = ft_strlen(s1);
        	s2_len = ft_strlen(s2);
        	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
        	if (!ret)
        		return (0);
        	ft_strlcpy(ret, s1, s1_len + 1);
        	ft_strcpy(ret + s1_len, s2, s2_len + 1);
        	return (ret);
        }
        ```
        
- **ft_strtrim**
    - 함수 설명
        - Prototype
        
        ```c
        char *ft_strtrim(char const *s1, char const *set);
        ```
        
        - **Description**
        
        Allocates (with malloc(3)) and returns a copy of
        ’s1’ with the characters specified in ’set’ removed
        from the beginning and the end of the string.
        
        - **Return value**
        
        The trimmed string. NULL if the allocation fails.
        
    - **code**
        
        앞뒤로 set(안의 character)이 들어가 있는 부분만 잘라서 중간에 있는 부분만 동적할당하여 리턴, 만약 가득 차있다면 빈 배열을 리턴.
        
        ```c
        #include "libft.h"
        
        char	*ft_strtrim(char const *s1, char const *set)
        {
        	char	*start;
        	char	*end;
        	char	*ret;
        
        	if (!s1)
        		return (0);
        	if (!set)
        		return (ft_strdup(s1));
        	start = (char *)s1;
        	while (*start && ft_strchr(set, *start))
        		++start;
        	end = (char *)s1 + ft_strlen(s1);
        	while (end > start && ft_strchr(set, *(end - 1)))
        		--end;
        	ret = (char *)malloc(sizeof(char) * (end - start + 1));
        	if (!ret)
        		return (0);
        	ft_strlcpy(ret, start, end - start + 1);
        	return (ret);
        }
        ```
        
- **ft_split**
    - 함수 설명
        - Prototype
        
        ```c
        char **ft_split(char const *s, char c);
        ```
        
        - **Description**
        
        Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the
        character ’c’ as a delimiter. The array must be ended by a NULL pointer.
        
        - **Return value**
        
        The array of new strings resulting from the split.
        NULL if the allocation fails.
        
    - **code**
        
        s배열을 캐릭터c로 분할을 해주는 함수.
        
        ```c
        #include "libft.h"
        
        static char	**ft_malloc_error(char **ret)
        {
        	unsigned int	i;
        
        	i = 0;
        	while (ret[i])
        	{
        		free(ret[i]);
        		++i;
        	}
        	free(ret);
        	return (0);
        }
        
        static size_t	ft_get_word_cnt(const char *s, char c)
        {
        	size_t	cnt;
        
        	cnt = 0;
        	while (*s)
        	{
        		if (*s != c)
        		{
        			++cnt;
        			while (*s && *s != c)
        				++s;
        			if (!*s)
        				break ;
        		}
        		++s;
        	}
        	return (cnt);
        }
        
        static size_t	ft_get_word_len(char const *s, char c)
        {
        	size_t	i;
        
        	i = 0;
        	while (*s && *s != c)
        	{
        		++s;
        		++i;
        	}
        	return (i);
        }
        
        char	**ft_split(char const *s, char c)
        {
        	char	**ret;
        	size_t	word_len;
        	size_t	i;
        
        	if (!s)
        		return (0);
        	ret = (char **)malloc(sizeof(char *) * (ft_get_word_cnt(s, c) + 1));
        	if (!ret)
        		return (0);
        	i = 0;
        	while (*s)
        	{
        		if (*s != c)
        		{
        			word_len = ft_get_word_len(s, c);
        			ret[i] = (char *)malloc(word_len + 1);
        			if (!ret[i])
        				return (ft_malloc_error(ret)); //실패시 처음부터 free
        			ft_strlcpy(ret[i++], s, word_len + 1);
        			s += word_len - 1; //s가 널을 만났을때 정상적으로 종료하기 위해 -1
        		}
        		++s;
        	}
        	ret[i] = 0;
        	return (ret);
        }
        ```
        
- **ft_itoa**
    - 함수 설명
        - Prototype
        
        ```c
        char *ft_itoa(int n);
        ```
        
        - **Description**
        
        Allocates (with malloc(3)) and returns a string
        representing the integer received as an argument.
        Negative numbers must be handled.
        
        - **Return value**
        
        The string representing the integer. NULL if the
        allocation fails.
        
    - **code**
        
        int 를 받아 숫자 문자열로 변환
        
        ```c
        #include "libft.h"
        
        static int	ft_abs(int n)
        {
        	if (n < 0)
        		return (-n);
        	return (n);
        }
        
        static int	ft_get_num_len(int n) //자리수 세기
        {
        	int	len;
        
        	len = 0;
        	if (n <= 0)
        		len = 1;
        	while (n != 0) //0일때도 1 해줘야함
        	{
        		n /= 10;
        		++len;
        	}
        	return (len);
        }
        
        char	*ft_itoa(int n)
        {
        	int		len;
        	int		sign;
        	char	*ret;
        
        	sign = 1;
        	if (n < 0)
        		sign = -1;
        	len = ft_get_num_len(n);
        	ret = (char *)malloc(sizeof(char) * (len + 1));
        	if (!ret)
        		return (0);
        	ret[len--] = 0;
        	while (len >= 0)
        	{
        		ret[len--] = ft_abs(n % 10) + '0';
        		n = ft_abs(n / 10);
        	}
        	if (sign == -1)
        		ret[0] = '-';
        	return (ret);
        }
        ```
        
- **ft_strmapi**
    - 함수 설명
        - Prototype
        
        ```c
        char *ft_strmapi(char const *s, char (*f)(unsigned
        int, char));
        ```
        
        - **Description**
        
        Applies the function ’f’ to each character of
        the string ’s’ , and passing its index as first
        argument to create a new string (with malloc(3))
        resulting from successive applications of ’f’.
        
        - **Return value**
        
        The string created from the successive applications
        of ’f’. Returns NULL if the allocation fails.
        
    - **code**
        
        s string에 있는 모든 character 에게 함수 f를 적용시키고 동적할당하여 배열에 저장 후 return
        
        ```c
        #include "libft.h"
        
        char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
        {
        	char			*ret;
        	unsigned int	len;
        	unsigned int	i;
        
        	if (!s || !f)
        		return (0);
        	len = ft_strlen(s);
        	ret = (char *)malloc(sizeof(char) * (len + 1));
        	if (!ret)
        		return (0);
        	i = 0;
        	while (s[i])
        	{
        		ret[i] = f(i, s[i]);
        		++i;
        	}
        	ret[i] = 0;
        	return (ret);
        }
        ```
        
- **ft_striteri**
    - 함수 설명
        - Prototype
        
        ```c
        void ft_striteri(char *s, void (*f)(unsigned int,
        char*));
        ```
        
        - **Description**
        
        Applies the function f to each character of the
        string passed as argument, and passing its index
        as first argument. Each character is passed by
        address to f to be modified if necessary
        
        - **Return value**
        
        None
        
    - **code**
        
        s에 f를 적용하여 리턴
        
        ```c
        #include "libft.h"
        
        void	ft_striteri(char *s, void (*f)(unsigned int, char*))
        {
        	unsigned int	i;
        
        	i = 0;
        	if (!s || !f)
        		return ;
        	while (*s)
        	{
        		f(i, s);
        		++s;
        		++i;
        	}
        }
        ```
        
- **ft_putchar_fd**
    - 함수 설명
        - Prototype
        
        ```c
        void ft_putchar_fd(char c, int fd);
        ```
        
        - **Description**
        
        Outputs the character ’c’ to the given file
        descriptor.
        
        - **Return value**
        
        None
        
    - **code**
        
        fd에 c 출력
        
        ```c
        #include "libft.h"
        
        void	ft_putchar_fd(char c, int fd)
        {
        	if (fd < 0)
        		return ;
        	write(fd, &c, 1);
        }
        ```
        
- **ft_putstr_fd**
    - 함수 설명
        - Prototype
        
        ```c
        void ft_putstr_fd(char *s, int fd);
        ```
        
        - **Description**
        
        Outputs the string ’s’ to the given file
        descriptor.
        
        - **Return value**
        
        None
        
    - **code**
        
        fd에 문자열 s 출력
        
        ```c
        #include "libft.h"
        
        void	ft_putstr_fd(char *s, int fd)
        {
        	if (!s || fd < 0)
        		return ;
        	write(fd, s, ft_strlen(s));
        }
        ```
        
- **ft_putendl_fd**
    - 함수 설명
        - Prototype
        
        ```c
        void ft_putendl_fd(char *s, int fd);
        ```
        
        - **Description**
        
        Outputs the string ’s’ to the given file
        descriptor, followed by a newline.
        
        - **Return value**
        
        None
        
    - **code**
        
        fd에 문자열 출력 후 줄바꿈
        
        ```c
        #include "libft.h"
        
        void	ft_putendl_fd(char *s, int fd)
        {
        	if (!s || fd < 0)
        		return ;
        	write(fd, s, ft_strlen(s));
        	write(fd, "\n", 1);
        }
        ```
        
- **ft_putnbr_fd**
    - 함수 설명
        - Prototype
        
        ```c
        void ft_putnbr_fd(int n, int fd);
        ```
        
        - **Description**
        
        Outputs the integer ’n’ to the given file
        descriptor.
        
        - **Return value**
        
        None
        
    - **code**
        
        fd에 int를 재귀로 출력
        
        ```c
        #include "libft.h"
        
        static void	ft_print_nbr(int n, int fd)
        {
        	if (n > 9)
        		ft_print_nbr(n / 10, fd);
        	write(fd, &"0123456789"[n % 10], 1);
        }
        
        void	ft_putnbr_fd(int n, int fd)
        {
        	if (fd < 0)
        		return ;
        	if (n == -2147483648)
        	{
        		write(fd, "-2147483648", 11);
        		return ;
        	}
        	if (n < 0)
        	{
        		write(fd, "-", 1);
        		n *= -1;
        	}
        	ft_print_nbr(n, fd);
        }
        ```
        

## bonus part

---

- **ft_lstnew**
    - 함수 설명
        - Prototype
        
        ```c
        t_list *ft_lstnew(void *content);
        ```
        
        - **Description**
        
        Allocates (with malloc(3)) and returns a new
        element. The variable ’content’ is initialized
        with the value of the parameter ’content’. The
        variable ’next’ is initialized to NULL.
        
        - **Return value**
        
        The new element.
        
    - **code**
        
        새로운 리스트를 동적할당 후 content 값 대입
        
        ```c
        #include "libft.h"
        
        t_list	*ft_lstnew(void *content)
        {
        	t_list	*new_list;
        
        	new_list = (t_list *)malloc(sizeof(t_list));
        	if (!new_list)
        		return (0);
        	new_list->content = content;
        	new_list->next = 0;
        	return (new_list);
        }
        ```
        
- **ft_lstadd_front**
    - 함수 설명
        - Prototype
        
        ```c
        void ft_lstadd_front(t_list **lst, t_list *new);
        ```
        
        - **Description**
        
        Adds the element ’new’ at the beginning of the
        list.
        
        - **Return value**
        
        None
        
    - **code**
        
        lst의 맨 앞에 new를 추가 후 *lst를 new의 주소로 변경
        
        ```c
        #include "libft.h"
        
        void	ft_lstadd_front(t_list **lst, t_list *new)
        {
        	if (!lst || !new)
        		return ;
        	new->next = *lst;
        	*lst = new;
        }
        ```
        
        - **연결리스트 이중포인터**
            
            ### 1. 연결 리스트 구현시 이중 포인터를 사용하는 이유
            
            - 단일 연결리스트에서 삽입과 삭제를 통해 head 포인터의 값을 변화시킬 수 있다.
            - 이때, 호출 함수의 포인터변수가 참조하는 객체를 피호출 함수에서 바꾸고자 할 경우 이중 포인터를 사용하면 된다.
            - `t_list **lst` 는 **t_list 포인터(lst)의 주소를 가리키는 포인터**다.
                - `t_list **lst` 변수가 담고있는 값은 `t_list *`의 주소
                - `t_list **lst`가 담고 있는 `t_list *` 의 주소는 어떤 리스트(lst)의 첫번째 주소
                - 즉, *lst는 head의 주소
            
            ### 2. *lst == NULL 과 lst == NULL 의 차이
            
            - *lst는 lst의 첫번째 주소, 즉 헤드의 주소를 의미한다. 헤드가 비었다는 건, 
            ***lst는 빈 리스트** 라는 뜻!
            - lst == NULL은 리스트 자체가 존재하지 않는다 뜻!
        
- **ft_lstsize**
    - 함수 설명
        - Prototype
        
        ```c
        int ft_lstsize(t_list *lst);
        ```
        
        - **Description**
        
        Counts the number of elements in a list.
        
        - **Return value**
        
        Length of the list
        
    - **code**
        
        lst를 끝까지 돌고 리스트의 크기를 리턴
        
        ```c
        #include "libft.h"
        
        int	ft_lstsize(t_list *lst)
        {
        	int	size;
        
        	size = 0;
        	while (lst)
        	{
        		lst = lst->next;
        		++size;
        	}
        	return (size);
        }
        ```
        
- **ft_lstlast**
    - 함수 설명
        - Prototype
        
        ```c
        t_list *ft_lstlast(t_list *lst);
        ```
        
        - **Description**
        
        Returns the last element of the list.
        
        - **Return value**
        
        Last element of the list.
        
    - **code**
        
        리스트의 마지막 주소를 리턴
        
        ```c
        #include "libft.h"
        
        t_list	*ft_lstlast(t_list *lst)
        {
        	if (!lst)
        		return (0);
        	while (lst->next)
        		lst = lst->next;
        	return (lst);
        }
        ```
        
- **ft_lstadd_back**
    - 함수 설명
        - Prototype
        
        ```c
        void ft_lstadd_back(t_list **lst, t_list *new);
        ```
        
        - **Description**
        
        Adds the element ’new’ at the end of the list.
        
        - **Return value**
        
        None
        
    - **code**
        
        new를 lst마지막에 추가
        
        ```c
        #include "libft.h"
        
        void	ft_lstadd_back(t_list **lst, t_list *new)
        {
        	t_list	*last;
        
        	if (!lst || !new)
        		return ;
        	if (!*lst)
        	{
        		*lst = new;
        		return ;
        	}
        	last = ft_lstlast(*lst);
        	last->next = new;
        }
        ```
        
        - **연결리스트 이중포인터**
            
            ### 1. 연결 리스트 구현시 이중 포인터를 사용하는 이유
            
            - 단일 연결리스트에서 삽입과 삭제를 통해 head 포인터의 값을 변화시킬 수 있다.
            - 이때, 호출 함수의 포인터변수가 참조하는 객체를 피호출 함수에서 바꾸고자 할 경우 이중 포인터를 사용하면 된다.
            - `t_list **lst` 는 **t_list 포인터(lst)의 주소를 가리키는 포인터**다.
                - `t_list **lst` 변수가 담고있는 값은 `t_list *`의 주소
                - `t_list **lst`가 담고 있는 `t_list *` 의 주소는 어떤 리스트(lst)의 첫번째 주소
                - 즉, *lst는 head의 주소
            
            ### 2. *lst == NULL 과 lst == NULL 의 차이
            
            - *lst는 lst의 첫번째 주소, 즉 헤드의 주소를 의미한다. 헤드가 비었다는 건, 
            ***lst는 빈 리스트** 라는 뜻!
            - lst == NULL은 리스트 자체가 존재하지 않는다 뜻!
            
- **ft_lstdelone**
    - 함수 설명
        - Prototype
        
        ```c
        void ft_lstdelone(t_list *lst, void (*del)(void *));
        ```
        
        - **Description**
        
        Takes as a parameter an element and frees the
        memory of the element’s content using the function
        ’del’ given as a parameter and free the element.
        The memory of ’next’ must not be freed.
        
        - **Return value**
        
        None
        
    - **code**
        
        lst 의 content를 지워주고 free
        
        ```c
        #include "libft.h"
        
        void	ft_lstdelone(t_list *lst, void (*del)(void *))
        {
        	if (!lst || !del)
        		return ;
        	del(lst->content);
        	free(lst); 
        }
        //content가 지워지지 않고 lst를 free 하면 그 content는 지워지지않고 남아있기때문에 
        //del 이 null이면 가드
        ```
        
- **ft_lstclear**
    - 함수 설명
        - Prototype
        
        ```c
        void ft_lstclear(t_list **lst, void (*del)(void *));
        ```
        
        - **Description**
        
        Deletes and frees the given element and every
        successor of that element, using the function ’del’
        and free(3).
        Finally, the pointer to the list must be set to
        NULL.
        
        - **Return value**
        
        None
        
    - **code**
        
        lst의 모든 노드를 지움
        
        ```c
        #include "libft.h"
        
        void	ft_lstclear(t_list **lst, void (*del)(void *))
        {
        	t_list	*curr;
        	t_list	*next;
        
        	curr = *lst;
        	while (curr)
        	{
        		next = curr->next;
        		ft_lstdelone(curr, del);
        		curr = next;
        	}
        	*lst = 0;
        }
        ```
        
- **ft_lstiter**
    - 함수 설명
        - Prototype
        
        ```c
        void ft_lstiter(t_list *lst, void (*f)(void *));
        ```
        
        - **Description**
        
        Iterates the list ’lst’ and applies the function
        ’f’ to the content of each element.
        
        - **Return value**
        
        None
        
    - **code**
        
        lst의 content에 f를 모두 적용
        
        ```c
        #include "libft.h"
        
        void	ft_lstiter(t_list *lst, void (*f)(void *))
        {
        	if (!lst || !f)
        		return ;
        	while (lst)
        	{
        		f(lst->content);
        		lst = lst->next;
        	}
        }
        ```
        
- **ft_lstmap**
    - 함수 설명
        - Prototype
        
        ```c
        t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
        void (*del)(void *));
        ```
        
        - **Description**
        
        Iterates the list ’lst’ and applies the function
        ’f’ to the content of each element. Creates a new
        list resulting of the successive applications of
        the function ’f’. The ’del’ function is used to
        delete the content of an element if needed.
        
        - **Return value**
        
        The new list. NULL if the allocation fails.
        
    - **code**
        
        lst 에 f를 적용 시킨 새로운 리스트를 리턴, 중간에 실패시 모두 free 해주기 위해 lstclear
        
        ```c
        #include "libft.h"
        
        t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
        {
        	t_list	*ret;
        	t_list	*cur;
        
        	if (!lst || !f) // !del을 하지 않은 이유는 ft_lstmap이란 함수가 새로운 리스트를 만드는
        		return (0); //것으 목표이기 때문에 del이 null이여도 정상적으로 리스트를 생성 할 수도 있기 때문
        	ret = ft_lstnew(f(lst->content));
        	if (!ret)
        		return (0);
        	lst = lst->next;
        	cur = ret;
        	while (lst)
        	{
        		cur->next = ft_lstnew(f(lst->content));
        		if (!(cur->next))
        		{
        			ft_lstclear(&ret, del);
        			return (0);
        		}
        		cur = cur->next;
        		lst = lst->next;
        	}
        	return (ret);
        }
        
        //ft_lstadd_back 에서 처음부터 다시 끝을 찾기 때문에 느림
        /*
        #include "libft.h"
        
        t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
        {
        	t_list	*ret;
        	t_list	*tmp;
        
        	if (!lst || !f)
        		return (0);
        	ret = 0;
        	while (lst)
        	{
        		tmp = ft_lstnew((*f)(lst->content));
        		if (!tmp)
        		{
        			ft_lstclear(&ret, del);
        			return (0);
        		}
        		ft_lstadd_back(&ret, tmp);
        		lst = lst->next;
        	}
        	return (ret);
        }
        */
        ```
        

## Makefile

---

[Makefile 부시기](Libft%20989e38c227e0455aada0c8a8b46f1931/Makefile%20%E1%84%87%E1%85%AE%E1%84%89%E1%85%B5%E1%84%80%E1%85%B5%20ef4aebabee3c4c1d9de1acdffb221636.md)

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER = libft.h
SRCS = \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
	  ft_substr.c \
		ft_tolower.c \
		ft_striteri.c \
		ft_toupper.c
B_SRCS = \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJS = $(SRCS:.c=.o)  

B_OBJS = $(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

bonus: $(OBJS) $(B_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^
	ar rc $(NAME) $@
# 오브젝트 파일을 생성할 때마다 아카이브에 추가한다.
		
clean:
	    rm -f $(OBJS) $(B_OBJS)

fclean: clean
	    rm -f $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
```
