<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>

<%@page import="java.sql.*"%>
<%@page import="java.util.*"%>


<%
String name = request.getParameter("name");
String email = request.getParameter("email");
String password = request.getParameter("p1");
String contact = request.getParameter("contact");

try {
	Class.forName("com.mysql.jdbc.Driver");

	Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/epicreview", "root", "");

	Statement st = con.createStatement();

	int i = st.executeUpdate("INSERT INTO authenticate values('"+name+"','"+email+"','"+password+"','"+contact+"')");

	response.sendRedirect("registered-banner.jsp");

} catch (Exception e) {
	e.printStackTrace();
}
%>