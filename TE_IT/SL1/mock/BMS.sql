-- MySQL dump 10.13  Distrib 5.7.27, for Linux (x86_64)
--
-- Host: localhost    Database: BMS
-- ------------------------------------------------------
-- Server version	5.7.27-0ubuntu0.16.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `account` (
  `ac_no` int(11) NOT NULL,
  `type` varchar(10) DEFAULT NULL,
  `date_of_opening` date DEFAULT NULL,
  `balance` bigint(20) DEFAULT NULL,
  PRIMARY KEY (`ac_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES (1001,'savings','2019-08-21',0),(1002,'savings','2019-08-21',7000),(1003,'current','2019-07-01',1000),(1004,'savings','2019-06-21',78000),(1008,'current','2016-05-21',3000);
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer` (
  `c_id` int(11) NOT NULL,
  `c_name` varchar(30) DEFAULT NULL,
  `address` varchar(40) DEFAULT NULL,
  `age` smallint(6) DEFAULT NULL,
  `contact` bigint(20) DEFAULT NULL,
  `email` varchar(30) DEFAULT NULL,
  `ac_no` int(11) DEFAULT NULL,
  PRIMARY KEY (`c_id`),
  KEY `ac_no` (`ac_no`),
  CONSTRAINT `customer_ibfk_1` FOREIGN KEY (`ac_no`) REFERENCES `account` (`ac_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES (1,'Sahil','PUNE',21,9545727831,'imsahil@gmail.com',1004),(2,'Manas','DHULE',20,8585828881,'manas@gmail.com',1001),(3,'Sanket','Nashik',20,7575878881,'sanket@gmail.com',1002),(4,'Jayesh','MALEGOAN',20,7665868881,'jayesh@mymail.com',1003),(5,'ABC','JALGAON',20,8576878881,'rupesh@hotmail.com',1008);
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `loan`
--

DROP TABLE IF EXISTS `loan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `loan` (
  `l_id` int(11) NOT NULL,
  `ac_no` int(11) DEFAULT NULL,
  `loan_date` date DEFAULT NULL,
  `l_amount` bigint(20) DEFAULT NULL,
  PRIMARY KEY (`l_id`),
  KEY `ac_no` (`ac_no`),
  CONSTRAINT `loan_ibfk_1` FOREIGN KEY (`ac_no`) REFERENCES `account` (`ac_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `loan`
--

LOCK TABLES `loan` WRITE;
/*!40000 ALTER TABLE `loan` DISABLE KEYS */;
INSERT INTO `loan` VALUES (1,1001,'2019-01-07',80000),(2,1001,'2019-05-21',82000),(3,1002,'2019-01-07',800000),(4,1008,'2019-06-20',75000);
/*!40000 ALTER TABLE `loan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transaction`
--

DROP TABLE IF EXISTS `transaction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `transaction` (
  `t_id` int(11) NOT NULL,
  `ac_no` int(11) DEFAULT NULL,
  `t_date` date DEFAULT NULL,
  `credit_amount` bigint(20) DEFAULT NULL,
  `debit_amount` bigint(20) DEFAULT NULL,
  PRIMARY KEY (`t_id`),
  KEY `ac_no` (`ac_no`),
  CONSTRAINT `transaction_ibfk_1` FOREIGN KEY (`ac_no`) REFERENCES `account` (`ac_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transaction`
--

LOCK TABLES `transaction` WRITE;
/*!40000 ALTER TABLE `transaction` DISABLE KEYS */;
INSERT INTO `transaction` VALUES (1,1004,'2019-09-05',5000,NULL),(2,1004,'2019-09-05',NULL,15000),(3,1001,'2019-09-05',150000,NULL),(4,1001,'2019-06-06',18000,NULL);
/*!40000 ALTER TABLE `transaction` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-09-05 16:02:35
