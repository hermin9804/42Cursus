/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:37:24 by mher              #+#    #+#             */
/*   Updated: 2022/05/16 19:14:34 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <termcap.h>

int main(void)
{
	int c;
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;    // non-canonical input 설정
	term.c_lflag &= ~ECHO;      // 입력 시 터미널에 보이지 않게
	term.c_cc[VMIN] = 1;        // 최소 입력 버퍼 크기
	term.c_cc[VTIME] = 0;       // 버퍼 비우는 시간 (timeout)
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	c = 0;
	while (read(STDIN_FILENO, &c, sizeof(c)) > 0)
	{
		printf("keycode: %d\n", c);
		c = 0;
	}

	char *env = getenv("TERM");
	if (env == NULL)
		env = "xterm";

	tgetent(NULL, env);                // xterm 설정 사용
	char *cm = tgetstr("cm", NULL);    //cursor motion
	char *ce = tgetstr("ce", NULL);    //clear line from cursor
	return 0;
}
