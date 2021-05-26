<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>

<%@page import="java.sql.*"%>
<%@page import="java.util.*"%>

<%
String fullname = request.getParameter("fullname");
String email = request.getParameter("email");
String question = request.getParameter("question");

try {
	Class.forName("com.mysql.jdbc.Driver");

	Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/epicreview", "root", "");

	Statement st = con.createStatement();

	int i = st.executeUpdate("INSERT INTO contact values('"+fullname+"','"+email+"','"+question+"')");

	response.sendRedirect("contactus-banner.jsp");

} catch (Exception e) {
	e.printStackTrace();
}
%>



<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

</body>
</html>