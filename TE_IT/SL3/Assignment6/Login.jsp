<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@page import="java.sql.*" %>
    
    <% 
String uname = request.getParameter("uname");
		String pass = request.getParameter("pass");

		try {
			Class.forName("org.mariadb.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mariadb://localhost:3306/a6", "Sahil", "Sahil@123");
			out.println("Connected");
			String query = "select pass from auth where uname='" + uname + "'";
			Statement st = con.createStatement();
			ResultSet rs = st.executeQuery(query);

			if (rs.next()) {
				if (rs.getString("pass").equals(pass)) {
					out.println("<script>alert('Access Granted')</script>");
					 response.sendRedirect("./index.html"); 
				} else {
					out.println("<script>alert('Invalid Crentials')</script>");
					 response.sendRedirect("home.html"); 
				}
			} else {
				out.println("<script>alert('No user Exists with Entered Username')</script>");
				 response.sendRedirect("home.html"); 

			}
			con.close();
			st.close();
			rs.close();
		} catch (Exception e) {
			out.println("Cant connect"+e.getMessage());
		}
    %>