<%@ page contentType="text/html;charset=euc-kr" %>

<HTML>
<HEAD>
<TITLE> Quiz 3 - 산술연산 </TITLE>
</HEAD>
<BODY>

<%
int Sum = 0;
int Num = 1;

// for문을 사용하여 정수형 변수 Num이
// 1부터 5씩 증가하면서 50이 되기 전까지 실행
for(;Num < 50; Num+=5      )
{
	// 짝수이면 덧셈, 홀수이면 뺄셈하고
	// 연산 과정을 출력
	if(Num % 2 == 0) Sum = Sum + Num;
	else Sum = Sum -Num;

}

<%-- 결과 출력 -->
out.print("=" + Sum);
%>

</BODY>
</HTML>
