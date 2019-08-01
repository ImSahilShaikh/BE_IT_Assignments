-- MySQL dump 10.17  Distrib 10.3.15-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: OMS
-- ------------------------------------------------------
-- Server version	10.3.15-MariaDB-1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `category`
--

DROP TABLE IF EXISTS `category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `category` (
  `cat_id` smallint(6) NOT NULL,
  `cat_name` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`cat_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `category`
--

LOCK TABLES `category` WRITE;
/*!40000 ALTER TABLE `category` DISABLE KEYS */;
INSERT INTO `category` VALUES (1,'Honda'),(2,'Suzuki'),(3,'Vespa'),(4,'TVS'),(5,'Bajaj'),(6,'Hero'),(7,'Enfield');
/*!40000 ALTER TABLE `category` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `contains`
--

DROP TABLE IF EXISTS `contains`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `contains` (
  `o_id` smallint(6) DEFAULT NULL,
  `qty` smallint(6) DEFAULT NULL,
  `p_id` smallint(6) DEFAULT NULL,
  KEY `o_id` (`o_id`),
  KEY `p_id` (`p_id`),
  CONSTRAINT `contains_ibfk_1` FOREIGN KEY (`o_id`) REFERENCES `myorder` (`o_id`) ON DELETE CASCADE,
  CONSTRAINT `contains_ibfk_2` FOREIGN KEY (`p_id`) REFERENCES `product` (`p_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `contains`
--

LOCK TABLES `contains` WRITE;
/*!40000 ALTER TABLE `contains` DISABLE KEYS */;
INSERT INTO `contains` VALUES (1,1,23),(3,2,27),(5,1,19),(12,3,2);
/*!40000 ALTER TABLE `contains` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer` (
  `c_id` smallint(6) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `email` varchar(20) DEFAULT NULL,
  `phone` bigint(20) DEFAULT NULL,
  `address` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`c_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES (1,'Sahil','sahil@gmail.com',9545727831,'PUNE'),(2,'Manish','manish@yahoo.com',9874561230,'PUNE'),(3,'Swapnil','swapnil@rediff.com',9988774455,'NASHIK'),(4,'Sanket','sanket@hotmail.com',8877994455,'NASHIK'),(5,'Rupesh','rupesh@rediff.com',9977664455,'JALGAON');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `myorder`
--

DROP TABLE IF EXISTS `myorder`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `myorder` (
  `o_id` smallint(6) NOT NULL,
  `c_id` smallint(6) DEFAULT NULL,
  `o_date` date DEFAULT NULL,
  `tax` int(11) DEFAULT NULL,
  `amount` int(11) DEFAULT NULL,
  PRIMARY KEY (`o_id`),
  KEY `c_id` (`c_id`),
  CONSTRAINT `myorder_ibfk_1` FOREIGN KEY (`c_id`) REFERENCES `customer` (`c_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `myorder`
--

LOCK TABLES `myorder` WRITE;
/*!40000 ALTER TABLE `myorder` DISABLE KEYS */;
INSERT INTO `myorder` VALUES (1,3,'2019-07-23',NULL,58000),(3,3,'2019-07-21',NULL,108354),(5,3,'2019-07-22',NULL,81000),(12,1,'2019-07-18',NULL,195000);
/*!40000 ALTER TABLE `myorder` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `product`
--

DROP TABLE IF EXISTS `product`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `product` (
  `p_id` smallint(6) NOT NULL,
  `p_name` varchar(20) DEFAULT NULL,
  `stock` smallint(6) DEFAULT NULL,
  `price` int(11) DEFAULT NULL,
  `cat_id` smallint(6) DEFAULT NULL,
  PRIMARY KEY (`p_id`),
  KEY `cat_id` (`cat_id`),
  CONSTRAINT `product_ibfk_1` FOREIGN KEY (`cat_id`) REFERENCES `category` (`cat_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `product`
--

LOCK TABLES `product` WRITE;
/*!40000 ALTER TABLE `product` DISABLE KEYS */;
INSERT INTO `product` VALUES (1,'Activa3g',25,60000,1),(2,'Activa4g',25,65000,1),(3,'Activa5g',25,67800,1),(4,'Dio',40,80000,1),(5,'Pulsar',15,90000,5),(6,'Dominar',10,17400,5),(7,'CB Hornet',30,86500,1),(8,'Platina',4,40749,5),(9,'Avenger',6,10400,5),(10,'Discover',5,54650,5),(11,'Gixxer',2,17100,2),(12,'Access125',8,55977,2),(13,'Hayabusa',5,1300000,2),(14,'Intruder',2,100000,2),(15,'Burgman',1,68000,2),(16,'Urban',4,73100,3),(17,'Notte125',1,73177,3),(18,'SXL',4,85000,3),(19,'VXL',3,81000,3),(20,'Elegant',4,101000,3),(21,'Apache160',14,79100,4),(22,'Jupiter',1,52177,4),(23,'NTORQ',7,58000,4),(24,'Sport',3,39000,4),(25,'Radeon',6,50000,4),(26,'Splendor',7,51000,6),(27,'Passion',50,54177,6),(28,'Glamour',7,61000,6),(29,'Maestro',5,51300,6),(30,'iSmart',6,56800,6),(31,'Classic',10,151000,7),(32,'Bullet',5,124177,7),(33,'Himalayan',3,179000,7),(34,'Interceptor',2,251000,7),(35,'Thunderbird',7,16400,7);
/*!40000 ALTER TABLE `product` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-08-01  9:12:10
