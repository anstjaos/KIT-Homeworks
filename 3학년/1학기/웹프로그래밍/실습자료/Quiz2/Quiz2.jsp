<%@ page contentType="text/html;charset=euc-kr" %>

<%
    String str = "Hello, Welcome to JSP World! Lets Go!";
%>

<HTML>
  <HEAD>
    <TITLE> Quiz 2 - 문자열 변환 함수 </TITLE>
  </HEAD>
  
  <BODY>
    <%-- String클래스의 length메소드를 사용하여 문자열의 길이 출력 --%>
    ① 입력되어 있는 문자열의 길이: <% out.print(str.length()); %> <BR>

    <%-- String클래스의 indexOf메소드를 사용하여 지정한 문자열의 위치 출력 --%>
    ② 'JSP'라는 문자 위치: <% out.print(str.indexOf("JSP")); %> <BR><BR>

    <%-- 문자열을 소문자로 변환하는 toLowerCase메소드의 적용 결과 --%>
    ③ 입력 문자열을 소문자로 변환: <% out.print(str.toLowerCase()); %><BR>

	<%-- 문자열을 대문자로 변환하는 toUpperCase메소드의 적용 결과 --%>
    ④ 입력 문자열을 대문자로 변환: <% out.print(str.toUpperCase()); %> <BR>
  </BODY>
</HTML>