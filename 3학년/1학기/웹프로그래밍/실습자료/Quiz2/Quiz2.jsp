<%@ page contentType="text/html;charset=euc-kr" %>

<%
    String str = "Hello, Welcome to JSP World! Lets Go!";
%>

<HTML>
  <HEAD>
    <TITLE> Quiz 2 - ���ڿ� ��ȯ �Լ� </TITLE>
  </HEAD>
  
  <BODY>
    <%-- StringŬ������ length�޼ҵ带 ����Ͽ� ���ڿ��� ���� ��� --%>
    �� �ԷµǾ� �ִ� ���ڿ��� ����: <% out.print(str.length()); %> <BR>

    <%-- StringŬ������ indexOf�޼ҵ带 ����Ͽ� ������ ���ڿ��� ��ġ ��� --%>
    �� 'JSP'��� ���� ��ġ: <% out.print(str.indexOf("JSP")); %> <BR><BR>

    <%-- ���ڿ��� �ҹ��ڷ� ��ȯ�ϴ� toLowerCase�޼ҵ��� ���� ��� --%>
    �� �Է� ���ڿ��� �ҹ��ڷ� ��ȯ: <% out.print(str.toLowerCase()); %><BR>

	<%-- ���ڿ��� �빮�ڷ� ��ȯ�ϴ� toUpperCase�޼ҵ��� ���� ��� --%>
    �� �Է� ���ڿ��� �빮�ڷ� ��ȯ: <% out.print(str.toUpperCase()); %> <BR>
  </BODY>
</HTML>