<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>

<%@page import="java.sql.*"%>
<%@page import="java.util.*"%>

<%
	String username = request.getParameter("username");
	String password = request.getParameter("password");
	
	try{
		Class.forName("com.mysql.jdbc.Driver");
		
		Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/epicreview","root","");
		
		String query = "select * from authenticate where username='"+username+"' and password='"+password+"'";
		
		Statement st = con.createStatement();
		
		ResultSet resultSet = st.executeQuery(query);
		
		out.println("Here after resultset");
		
		
		if(resultSet.next())
		{ 
			if(username.equals(resultSet.getString("username")) && password.equals(resultSet.getString("password")))
				{
					session.setAttribute("user", username);
					session.setAttribute("error", "None");
					response.sendRedirect("index.jsp");
					
				}
				else
				{
					session.setAttribute("user", "NoUser");
					session.setAttribute("error", "Incorrect username or Password");
					response.sendRedirect("Login.jsp");
					
				}
		}
		else
		{			
			session.setAttribute("user", "NoUser");
			session.setAttribute("error", "Incorrect username or Password");
			response.sendRedirect("Login.jsp");
		}  
	}
	catch(Exception e){
		e.printStackTrace();
	}
%>