-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: pankkisimulaattori
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `idasiakas` int NOT NULL AUTO_INCREMENT,
  `nimi` varchar(45) NOT NULL,
  `osoite` varchar(45) NOT NULL,
  `puhelinnro` varchar(45) NOT NULL,
  PRIMARY KEY (`idasiakas`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (1,'Sauli Partanen','Uusikatu','89455497'),(2,'Samuli Salmi','Rajakylä 666','708345543'),(3,'Tero','Vähäsarja','703454537');
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asiakas_pankkitili`
--

DROP TABLE IF EXISTS `asiakas_pankkitili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas_pankkitili` (
  `idasiakas` int NOT NULL,
  `tilinumero` int NOT NULL,
  PRIMARY KEY (`idasiakas`,`tilinumero`),
  KEY `fk_asiakas_pankkitili_pankkitili1_idx` (`tilinumero`),
  CONSTRAINT `fk_asiakas_pankkitili_asiakas` FOREIGN KEY (`idasiakas`) REFERENCES `asiakas` (`idasiakas`),
  CONSTRAINT `fk_asiakas_pankkitili_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas_pankkitili`
--

LOCK TABLES `asiakas_pankkitili` WRITE;
/*!40000 ALTER TABLE `asiakas_pankkitili` DISABLE KEYS */;
INSERT INTO `asiakas_pankkitili` VALUES (1,1),(2,2);
/*!40000 ALTER TABLE `asiakas_pankkitili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pankkikortti`
--

DROP TABLE IF EXISTS `pankkikortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pankkikortti` (
  `korttinumero` int NOT NULL,
  `pin` varchar(60) DEFAULT NULL,
  `credit` tinyint NOT NULL,
  `tilinumero` int NOT NULL,
  `pinVaarin` int DEFAULT '0',
  PRIMARY KEY (`korttinumero`,`tilinumero`),
  KEY `fk_pankkikortti_pankkitili1_idx` (`tilinumero`),
  CONSTRAINT `fk_pankkikortti_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkikortti`
--

LOCK TABLES `pankkikortti` WRITE;
/*!40000 ALTER TABLE `pankkikortti` DISABLE KEYS */;
INSERT INTO `pankkikortti` VALUES (1,'1',1,1,0),(2,'1',0,2,0);
/*!40000 ALTER TABLE `pankkikortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pankkitili`
--

DROP TABLE IF EXISTS `pankkitili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pankkitili` (
  `tilinumero` int NOT NULL,
  `saldo` float NOT NULL,
  `creditsaldo` float DEFAULT NULL,
  `luottoraja` int DEFAULT NULL,
  PRIMARY KEY (`tilinumero`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkitili`
--

LOCK TABLES `pankkitili` WRITE;
/*!40000 ALTER TABLE `pankkitili` DISABLE KEYS */;
INSERT INTO `pankkitili` VALUES (1,6700,-972,1),(2,568,10574,NULL),(3,1000,0,NULL);
/*!40000 ALTER TABLE `pankkitili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tapahtumat`
--

DROP TABLE IF EXISTS `tapahtumat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tapahtumat` (
  `idtapahtumat` int NOT NULL AUTO_INCREMENT,
  `aikaleima` datetime NOT NULL,
  `tapahtuma` varchar(45) NOT NULL,
  `summa` float NOT NULL,
  `credit` tinyint NOT NULL,
  `tilinumero` int NOT NULL,
  PRIMARY KEY (`idtapahtumat`),
  KEY `fk_tapahtumat_pankkitili1_idx` (`tilinumero`),
  CONSTRAINT `fk_tapahtumat_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=449 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tapahtumat`
--

LOCK TABLES `tapahtumat` WRITE;
/*!40000 ALTER TABLE `tapahtumat` DISABLE KEYS */;
INSERT INTO `tapahtumat` VALUES (147,'2021-12-09 16:36:52','siirto',1500,0,1),(148,'2021-12-09 16:36:52','talletus',1500,1,1),(149,'2021-12-09 16:37:13','otto',100,1,1),(150,'2021-12-09 16:37:13','talletus',100,0,2),(151,'2021-12-09 16:37:13','otto',100,1,1),(152,'2021-12-09 16:37:13','talletus',100,0,2),(153,'2021-12-09 16:37:14','otto',100,1,1),(154,'2021-12-09 16:37:14','talletus',100,0,2),(155,'2021-12-09 16:37:15','otto',100,1,1),(156,'2021-12-09 16:37:15','talletus',100,0,2),(157,'2021-12-09 16:37:16','otto',100,1,1),(158,'2021-12-09 16:37:16','talletus',100,0,2),(159,'2021-12-09 16:39:00','otto',-100,1,1),(160,'2021-12-09 16:39:00','talletus',100,0,2),(161,'2021-12-09 16:39:01','otto',-100,1,1),(162,'2021-12-09 16:39:01','talletus',100,0,2),(163,'2021-12-09 16:39:15','otto',-100,1,1),(164,'2021-12-09 16:39:15','talletus',100,0,2),(165,'2021-12-09 16:39:16','otto',-100,1,1),(166,'2021-12-09 16:39:16','talletus',100,0,2),(167,'2021-12-09 16:39:16','otto',-100,1,1),(168,'2021-12-09 16:39:16','talletus',100,0,2),(169,'2021-12-09 16:39:47','otto',-100,1,1),(170,'2021-12-09 16:39:47','talletus',100,0,2),(171,'2021-12-09 16:40:02','otto',-100,1,1),(172,'2021-12-09 16:40:02','talletus',100,0,2),(173,'2021-12-09 16:40:02','otto',-100,1,1),(174,'2021-12-09 16:40:02','talletus',100,0,2),(175,'2021-12-09 16:40:03','otto',-100,1,1),(176,'2021-12-09 16:40:03','talletus',100,0,2),(177,'2021-12-09 16:40:03','otto',-100,1,1),(178,'2021-12-09 16:40:03','talletus',100,0,2),(179,'2021-12-09 16:40:04','otto',-100,1,1),(180,'2021-12-09 16:40:04','talletus',100,0,2),(181,'2021-12-09 16:40:04','otto',-100,1,1),(182,'2021-12-09 16:40:04','talletus',100,0,2),(183,'2021-12-09 16:40:05','otto',-100,1,1),(184,'2021-12-09 16:40:05','talletus',100,0,2),(185,'2021-12-09 16:40:06','otto',-100,1,1),(186,'2021-12-09 16:40:06','talletus',100,0,2),(187,'2021-12-09 16:40:08','otto',-100,1,1),(188,'2021-12-09 16:40:08','talletus',100,0,2),(189,'2021-12-09 16:40:09','otto',-100,1,1),(190,'2021-12-09 16:40:09','talletus',100,0,2),(191,'2021-12-09 16:40:09','otto',-100,1,1),(192,'2021-12-09 16:40:09','talletus',100,0,2),(193,'2021-12-09 16:40:10','otto',-100,1,1),(194,'2021-12-09 16:40:10','talletus',100,0,2),(195,'2021-12-09 16:40:10','otto',-100,1,1),(196,'2021-12-09 16:40:10','talletus',100,0,2),(197,'2021-12-09 16:42:38','siirto',1500,0,1),(198,'2021-12-09 16:42:38','talletus',1500,1,1),(199,'2021-12-09 16:42:47','talletus',5000,0,1),(200,'2021-12-09 16:42:53','siirto',1500,0,1),(201,'2021-12-09 16:42:53','talletus',1500,1,1),(202,'2021-12-09 16:43:03','otto',-900,1,1),(203,'2021-12-09 16:43:03','talletus',900,0,2),(204,'2021-12-09 16:43:49','otto',-99,1,1),(205,'2021-12-09 16:43:49','talletus',99,0,2),(206,'2021-12-09 16:45:46','tilisiirto',-99,1,1),(207,'2021-12-09 16:45:46','talletus',99,0,2),(208,'2021-12-09 16:45:51','tilisiirto',-99,1,1),(209,'2021-12-09 16:45:51','talletus',99,0,2),(210,'2021-12-09 16:45:52','tilisiirto',-99,1,1),(211,'2021-12-09 16:45:52','talletus',99,0,2),(212,'2021-12-09 16:45:55','tilisiirto',-99,1,1),(213,'2021-12-09 16:45:55','talletus',99,0,2),(214,'2021-12-09 16:45:56','tilisiirto',-99,1,1),(215,'2021-12-09 16:45:56','talletus',99,0,2),(216,'2021-12-09 16:52:31','tilisiirto',-99,1,1),(217,'2021-12-09 16:52:31','talletus',99,0,2),(218,'2021-12-09 16:52:31','tilisiirto',-99,1,1),(219,'2021-12-09 16:52:31','talletus',99,0,2),(220,'2021-12-09 16:52:32','tilisiirto',-99,1,1),(221,'2021-12-09 16:52:32','talletus',99,0,2),(222,'2021-12-09 16:52:32','tilisiirto',-99,1,1),(223,'2021-12-09 16:52:32','talletus',99,0,2),(224,'2021-12-09 16:52:47','tilisiirto',-103,1,1),(225,'2021-12-09 16:52:47','talletus',103,0,2),(226,'2021-12-09 16:53:42','tilisiirto',-103,1,1),(227,'2021-12-09 16:53:42','talletus',103,0,2),(228,'2021-12-09 16:53:43','tilisiirto',-103,1,1),(229,'2021-12-09 16:53:43','talletus',103,0,2),(230,'2021-12-09 16:53:50','tilisiirto',-97,1,1),(231,'2021-12-09 16:53:50','talletus',97,0,2),(232,'2021-12-09 16:53:56','tilisiirto',-94,1,1),(233,'2021-12-09 16:53:56','talletus',94,0,2),(234,'2021-12-09 16:54:11','tilisiirto',-94,1,1),(235,'2021-12-09 16:54:11','talletus',94,0,2),(236,'2021-12-09 16:54:23','tilisiirto',-5,1,1),(237,'2021-12-09 16:54:23','talletus',5,0,2),(238,'2021-12-09 16:54:39','tilisiirto',-5,1,1),(239,'2021-12-09 16:54:39','talletus',5,0,2),(240,'2021-12-09 16:54:39','tilisiirto',-5,1,1),(241,'2021-12-09 16:54:39','talletus',5,0,2),(242,'2021-12-09 16:54:40','tilisiirto',-5,1,1),(243,'2021-12-09 16:54:40','talletus',5,0,2),(244,'2021-12-09 16:54:40','tilisiirto',-5,1,1),(245,'2021-12-09 16:54:40','talletus',5,0,2),(246,'2021-12-09 16:54:40','tilisiirto',-5,1,1),(247,'2021-12-09 16:54:40','talletus',5,0,2),(248,'2021-12-09 16:54:41','tilisiirto',-5,1,1),(249,'2021-12-09 16:54:41','talletus',5,0,2),(250,'2021-12-09 16:54:51','tilisiirto',-10,1,1),(251,'2021-12-09 16:54:51','talletus',10,0,2),(252,'2021-12-09 16:54:51','tilisiirto',-10,1,1),(253,'2021-12-09 16:54:51','talletus',10,0,2),(254,'2021-12-09 16:54:52','tilisiirto',-10,1,1),(255,'2021-12-09 16:54:52','talletus',10,0,2),(256,'2021-12-09 16:54:52','tilisiirto',-10,1,1),(257,'2021-12-09 16:54:52','talletus',10,0,2),(258,'2021-12-09 16:54:52','tilisiirto',-10,1,1),(259,'2021-12-09 16:54:52','talletus',10,0,2),(260,'2021-12-09 16:58:34','siirto',1500,0,1),(261,'2021-12-09 16:58:34','talletus',1500,1,1),(262,'2021-12-09 16:59:49','tilisiirto',-100,1,1),(263,'2021-12-09 16:59:49','talletus',100,0,2),(264,'2021-12-09 16:59:52','tilisiirto',-100,1,1),(265,'2021-12-09 16:59:52','talletus',100,0,2),(266,'2021-12-09 16:59:55','tilisiirto',-100,1,1),(267,'2021-12-09 16:59:55','talletus',100,0,2),(268,'2021-12-09 16:59:57','tilisiirto',-100,1,1),(269,'2021-12-09 16:59:57','talletus',100,0,2),(270,'2021-12-09 17:07:17','tilisiirto',-100,1,1),(271,'2021-12-09 17:07:17','talletus',100,0,2),(272,'2021-12-09 17:07:20','tilisiirto',-100,1,1),(273,'2021-12-09 17:07:20','talletus',100,0,2),(274,'2021-12-09 17:07:21','tilisiirto',-100,1,1),(275,'2021-12-09 17:07:21','talletus',100,0,2),(276,'2021-12-09 17:07:21','tilisiirto',-100,1,1),(277,'2021-12-09 17:07:21','talletus',100,0,2),(278,'2021-12-09 17:07:30','tilisiirto',-99,1,1),(279,'2021-12-09 17:07:30','talletus',99,0,2),(280,'2021-12-09 17:10:50','tilisiirto',-99,1,1),(281,'2021-12-09 17:10:50','talletus',99,0,2),(282,'2021-12-09 17:10:51','tilisiirto',-99,1,1),(283,'2021-12-09 17:10:51','talletus',99,0,2),(284,'2021-12-09 17:10:52','tilisiirto',-99,1,1),(285,'2021-12-09 17:10:52','talletus',99,0,2),(286,'2021-12-09 17:10:52','tilisiirto',-99,1,1),(287,'2021-12-09 17:10:52','talletus',99,0,2),(288,'2021-12-09 17:10:53','tilisiirto',-99,1,1),(289,'2021-12-09 17:10:53','talletus',99,0,2),(290,'2021-12-09 17:11:22','siirto',1500,0,1),(291,'2021-12-09 17:11:22','talletus',1500,1,1),(292,'2021-12-09 17:11:36','tilisiirto',-100,1,1),(293,'2021-12-09 17:11:36','talletus',100,0,2),(294,'2021-12-09 17:11:38','tilisiirto',-100,1,1),(295,'2021-12-09 17:11:38','talletus',100,0,2),(296,'2021-12-09 17:11:39','tilisiirto',-100,1,1),(297,'2021-12-09 17:11:39','talletus',100,0,2),(298,'2021-12-09 17:11:40','tilisiirto',-100,1,1),(299,'2021-12-09 17:11:40','talletus',100,0,2),(300,'2021-12-09 17:14:37','tilisiirto',-100,1,1),(301,'2021-12-09 17:14:37','talletus',100,0,2),(302,'2021-12-09 17:14:39','tilisiirto',-100,1,1),(303,'2021-12-09 17:14:39','talletus',100,0,2),(304,'2021-12-09 17:14:40','tilisiirto',-100,1,1),(305,'2021-12-09 17:14:40','talletus',100,0,2),(306,'2021-12-09 17:14:40','tilisiirto',-100,1,1),(307,'2021-12-09 17:14:40','talletus',100,0,2),(308,'2021-12-09 17:15:50','tilisiirto',-50,1,1),(309,'2021-12-09 17:15:50','talletus',50,0,2),(310,'2021-12-09 17:15:52','tilisiirto',-50,1,1),(311,'2021-12-09 17:15:52','talletus',50,0,2),(312,'2021-12-09 17:15:52','tilisiirto',-50,1,1),(313,'2021-12-09 17:15:52','talletus',50,0,2),(314,'2021-12-09 17:15:53','tilisiirto',-50,1,1),(315,'2021-12-09 17:15:53','talletus',50,0,2),(316,'2021-12-09 17:15:54','tilisiirto',-50,1,1),(317,'2021-12-09 17:15:54','talletus',50,0,2),(318,'2021-12-09 17:15:54','tilisiirto',-50,1,1),(319,'2021-12-09 17:15:54','talletus',50,0,2),(320,'2021-12-09 17:15:55','tilisiirto',-50,1,1),(321,'2021-12-09 17:15:55','talletus',50,0,2),(322,'2021-12-09 17:15:56','tilisiirto',-50,1,1),(323,'2021-12-09 17:15:56','talletus',50,0,2),(324,'2021-12-09 17:15:57','tilisiirto',-50,1,1),(325,'2021-12-09 17:15:57','talletus',50,0,2),(326,'2021-12-12 14:39:32','siirto',5000,0,2),(327,'2021-12-12 14:39:32','talletus',5000,1,2),(328,'2021-12-12 14:39:40','talletus',5000,0,1),(329,'2021-12-12 14:39:51','siirto',2000,0,2),(330,'2021-12-12 14:39:51','talletus',2000,1,2),(331,'2021-12-12 14:40:19','tilisiirto',-100,1,1),(332,'2021-12-12 14:40:19','talletus',100,0,2),(333,'2021-12-12 14:40:20','tilisiirto',-100,1,1),(334,'2021-12-12 14:40:20','talletus',100,0,2),(335,'2021-12-12 14:40:21','tilisiirto',-100,1,1),(336,'2021-12-12 14:40:21','talletus',100,0,2),(337,'2021-12-12 14:40:24','tilisiirto',-50,1,1),(338,'2021-12-12 14:40:24','talletus',50,0,2),(339,'2021-12-12 14:40:26','tilisiirto',-50,1,1),(340,'2021-12-12 14:40:26','talletus',50,0,2),(341,'2021-12-12 14:40:27','tilisiirto',-50,1,1),(342,'2021-12-12 14:40:27','talletus',50,0,2),(343,'2021-12-12 14:40:35','tilisiirto',-20,1,1),(344,'2021-12-12 14:40:35','talletus',20,0,2),(345,'2021-12-12 14:40:35','tilisiirto',-20,1,1),(346,'2021-12-12 14:40:35','talletus',20,0,2),(347,'2021-12-12 14:40:36','tilisiirto',-20,1,1),(348,'2021-12-12 14:40:36','talletus',20,0,2),(349,'2021-12-12 14:40:39','tilisiirto',-50,1,1),(350,'2021-12-12 14:40:39','talletus',50,0,2),(351,'2021-12-12 14:40:40','tilisiirto',-50,1,1),(352,'2021-12-12 14:40:40','talletus',50,0,2),(353,'2021-12-12 14:40:40','tilisiirto',-50,1,1),(354,'2021-12-12 14:40:40','talletus',50,0,2),(355,'2021-12-12 14:42:12','tilisiirto',-100,1,1),(356,'2021-12-12 14:42:12','talletus',100,0,2),(357,'2021-12-12 14:42:15','tilisiirto',-100,1,1),(358,'2021-12-12 14:42:15','talletus',100,0,2),(359,'2021-12-12 14:42:15','tilisiirto',-100,1,1),(360,'2021-12-12 14:42:15','talletus',100,0,2),(361,'2021-12-12 14:43:04','tilisiirto',-50,1,1),(362,'2021-12-12 14:43:04','talletus',50,0,2),(363,'2021-12-12 14:43:05','tilisiirto',-50,1,1),(364,'2021-12-12 14:43:05','talletus',50,0,2),(365,'2021-12-12 14:43:06','tilisiirto',-50,1,1),(366,'2021-12-12 14:43:06','talletus',50,0,2),(367,'2021-12-12 14:43:34','tilisiirto',-20,1,1),(368,'2021-12-12 14:43:34','talletus',20,0,2),(369,'2021-12-12 14:43:35','tilisiirto',-20,1,1),(370,'2021-12-12 14:43:35','talletus',20,0,2),(371,'2021-12-12 14:43:36','tilisiirto',-20,1,1),(372,'2021-12-12 14:43:36','talletus',20,0,2),(373,'2021-12-12 14:47:09','siirto',2000,0,1),(374,'2021-12-12 14:47:09','talletus',2000,1,1),(375,'2021-12-12 14:47:11','siirto',2000,0,1),(376,'2021-12-12 14:47:11','talletus',2000,1,1),(377,'2021-12-12 14:47:15','tilisiirto',-20,1,1),(378,'2021-12-12 14:47:15','talletus',20,0,2),(379,'2021-12-12 14:47:19','tilisiirto',-30,1,1),(380,'2021-12-12 14:47:19','talletus',30,0,2),(381,'2021-12-12 14:47:27','tilisiirto',-30,1,1),(382,'2021-12-12 14:47:27','talletus',30,0,2),(383,'2021-12-12 14:47:32','tilisiirto',-80,1,1),(384,'2021-12-12 14:47:32','talletus',80,0,2),(385,'2021-12-12 14:48:54','tilisiirto',-100,1,1),(386,'2021-12-12 14:48:54','talletus',100,0,2),(387,'2021-12-12 14:48:59','tilisiirto',-70,1,1),(388,'2021-12-12 14:48:59','talletus',70,0,2),(389,'2021-12-12 15:00:44','tilisiirto',-70,1,1),(390,'2021-12-12 15:00:44','talletus',70,0,2),(391,'2021-12-12 15:00:49','tilisiirto',-30,1,1),(392,'2021-12-12 15:00:49','talletus',30,0,2),(393,'2021-12-12 15:05:33','tilisiirto',-68,0,2),(394,'2021-12-12 15:05:33','tilisiirto',68,0,1),(395,'2021-12-12 15:05:44','tilisiirto',-100,0,2),(396,'2021-12-12 15:05:44','tilisiirto',100,0,1),(397,'2021-12-12 15:06:03','tilisiirto',-100,0,2),(398,'2021-12-12 15:06:03','tilisiirto',100,0,1),(399,'2021-12-12 15:06:06','tilisiirto',-500,0,2),(400,'2021-12-12 15:06:06','tilisiirto',500,0,1),(401,'2021-12-12 15:10:21','tilisiirto',-100,0,2),(402,'2021-12-12 15:10:21','tilisiirto',100,0,1),(403,'2021-12-12 15:10:22','tilisiirto',-100,0,2),(404,'2021-12-12 15:10:22','tilisiirto',100,0,1),(405,'2021-12-12 15:10:22','tilisiirto',-100,0,2),(406,'2021-12-12 15:10:22','tilisiirto',100,0,1),(407,'2021-12-12 15:10:23','tilisiirto',-100,0,2),(408,'2021-12-12 15:10:23','tilisiirto',100,0,1),(409,'2021-12-12 15:10:23','tilisiirto',-100,0,2),(410,'2021-12-12 15:10:23','tilisiirto',100,0,1),(411,'2021-12-12 15:11:07','tilisiirto',-1000,0,2),(412,'2021-12-12 15:11:07','tilisiirto',1000,0,1),(413,'2021-12-12 15:11:07','tilisiirto',-1000,0,2),(414,'2021-12-12 15:11:07','tilisiirto',1000,0,1),(415,'2021-12-12 15:11:08','tilisiirto',-1000,0,2),(416,'2021-12-12 15:11:08','tilisiirto',1000,0,1),(417,'2021-12-12 15:11:09','tilisiirto',-1000,0,2),(418,'2021-12-12 15:11:09','tilisiirto',1000,0,1),(419,'2021-12-12 15:17:00','tilisiirto',-100,0,1),(420,'2021-12-12 15:17:00','tilisiirto',100,0,2),(421,'2021-12-12 15:17:01','tilisiirto',-100,0,1),(422,'2021-12-12 15:17:01','tilisiirto',100,0,2),(423,'2021-12-12 15:17:03','tilisiirto',-100,0,1),(424,'2021-12-12 15:17:03','tilisiirto',100,0,2),(425,'2021-12-12 15:17:04','tilisiirto',-100,0,1),(426,'2021-12-12 15:17:04','tilisiirto',100,0,2),(427,'2021-12-12 15:17:06','tilisiirto',-100,0,1),(428,'2021-12-12 15:17:06','tilisiirto',100,0,2),(429,'2021-12-12 15:17:13','tilisiirto',-68,0,1),(430,'2021-12-12 15:17:13','tilisiirto',68,0,2),(431,'2021-12-12 15:18:29','tilisiirto',-50,1,1),(432,'2021-12-12 15:18:29','tilisiirto',50,1,2),(433,'2021-12-12 15:18:31','tilisiirto',-50,1,1),(434,'2021-12-12 15:18:31','tilisiirto',50,1,2),(435,'2021-12-12 15:18:32','tilisiirto',-50,1,1),(436,'2021-12-12 15:18:32','tilisiirto',50,1,2),(437,'2021-12-12 15:18:32','tilisiirto',-50,1,1),(438,'2021-12-12 15:18:32','tilisiirto',50,1,2),(439,'2021-12-12 15:18:33','tilisiirto',-50,1,1),(440,'2021-12-12 15:18:33','tilisiirto',50,1,2),(441,'2021-12-12 15:18:33','tilisiirto',-50,1,1),(442,'2021-12-12 15:18:33','tilisiirto',50,1,2),(443,'2021-12-12 15:18:34','tilisiirto',-50,1,1),(444,'2021-12-12 15:18:34','tilisiirto',50,1,2),(445,'2021-12-12 15:18:34','tilisiirto',-50,1,1),(446,'2021-12-12 15:18:34','tilisiirto',50,1,2),(447,'2021-12-12 15:19:23','tilisiirto',-2999,1,1),(448,'2021-12-12 15:19:23','tilisiirto',2999,1,2);
/*!40000 ALTER TABLE `tapahtumat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'pankkisimulaattori'
--
/*!50003 DROP PROCEDURE IF EXISTS `credit_tilisiirto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `credit_tilisiirto`(
IN id1 INT,
IN tilinumero2 INT,
IN creditKayttaja TINYINT,
IN creditVastaanottaja TINYINT,
IN summa DOUBLE,
OUT creditraja FLOAT)
BEGIN
  DECLARE test2,tilinumero1 INT DEFAULT 0;
  START TRANSACTION;
    SELECT pankkikortti.tilinumero INTO tilinumero1 FROM pankkikortti WHERE pankkikortti.korttinumero = id1; 
    SELECT luottoraja INTO creditraja FROM pankkitili WHERE tilinumero = tilinumero1;
	  IF (creditKayttaja = 1 AND creditVastaanottaja = 1 AND creditraja > summa) THEN UPDATE pankkitili SET creditsaldo=creditsaldo-summa WHERE tilinumero=tilinumero1;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET creditsaldo=creditsaldo+summa WHERE tilinumero=tilinumero2;
				UPDATE pankkitili SET luottoraja=luottoraja-summa WHERE tilinumero=tilinumero1;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', -summa, tilinumero1, '1');
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', summa, tilinumero2, '1');
			ELSE
			  ROLLBACK;
		  END IF;
	  END IF;
  
	  IF (creditKayttaja = 1 AND creditVastaanottaja = 0 AND creditraja > summa) THEN UPDATE pankkitili SET creditsaldo=creditsaldo-summa WHERE tilinumero=tilinumero1;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinumero2;
				UPDATE pankkitili SET luottoraja=luottoraja-summa WHERE tilinumero=tilinumero1;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', -summa, tilinumero1, '1');
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', summa, tilinumero2, '0');
		  ELSE ROLLBACK;
		  END IF;
	  END IF;
	SELECT luottoraja INTO creditraja FROM pankkitili WHERE tilinumero = tilinumero1;
	SELECT creditraja;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `credit_to_debit` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `credit_to_debit`(IN id1 INT, IN summa DOUBLE)
BEGIN
  DECLARE test1,test2 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=id1;
  SET test1=ROW_COUNT();
  UPDATE pankkitili SET creditsaldo=creditsaldo-summa WHERE tilinumero=id1;
  SET test2=ROW_COUNT();
    IF (test1 > 0 AND test2 >0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'talletus', summa, id1, '0');
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'siirto', summa, id1, '1');
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `debit_tilisiirto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_tilisiirto`(
IN id1 INT,
IN tilinumero2 INT,
IN creditKayttaja TINYINT,
IN creditVastaanottaja TINYINT,
IN summa DOUBLE,
OUT saldoUlos FLOAT)
BEGIN
  DECLARE test2,tilinumero1 INT DEFAULT 0;
  START TRANSACTION;
    SELECT pankkikortti.tilinumero INTO tilinumero1 FROM pankkikortti WHERE pankkikortti.korttinumero = id1; 
	  IF (creditKayttaja = 0 AND creditVastaanottaja = 1) THEN UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=tilinumero1 AND saldo>=summa;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinumero2;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', -summa, tilinumero1, '0');
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', summa, tilinumero2, '1');
			ELSE
			  ROLLBACK;
		  END IF;
	  END IF;
  
	  IF (creditKayttaja = 0 AND creditVastaanottaja = 0) THEN UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=tilinumero1 AND saldo>=summa;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinumero2;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', -summa, tilinumero1, '0');
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', summa, tilinumero2, '0');
		  ELSE ROLLBACK;
		  END IF;
	  END IF;
	SELECT saldo INTO saldoUlos FROM pankkitili WHERE tilinumero = tilinumero1;
    SELECT saldoUlos;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `debit_to_credit` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_to_credit`(IN id1 INT, IN summa DOUBLE)
BEGIN
  DECLARE test1,test2 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=id1 AND saldo>=summa;
  SET test1=ROW_COUNT();
  UPDATE pankkitili SET creditsaldo=creditsaldo+summa WHERE tilinumero=id1;
  SET test2=ROW_COUNT();
    IF (test1 > 0 AND test2 >0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'siirto', summa, id1, '0');
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'talletus', summa, id1, '1');
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `otto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `otto`(IN id1 INT, IN summa DOUBLE)
BEGIN
  DECLARE test1 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=id1 AND saldo>=summa;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'otto', summa, id1, '0');
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `pin_Katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `pin_Katsaus`(
IN id1 INT,
IN id2 TINYINT,
OUT laskuri INT
)
BEGIN
IF (id2 = 1) THEN UPDATE pankkikortti SET pankkikortti.pinVaarin=0 WHERE korttinumero=id1;
ELSE IF (id2 = 0) THEN
    UPDATE pankkikortti SET pankkikortti.pinVaarin=pankkikortti.pinVaarin+1 WHERE korttinumero=id1;
    SELECT pinVaarin INTO laskuri from pankkikortti WHERE korttinumero = id1;
END IF;
END IF;
IF (laskuri > 2) THEN DELETE FROM pankkikortti WHERE korttinumero = id1; 
END IF;
SELECT laskuri;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `saldo_katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `saldo_katsaus`(IN id1 INT)
BEGIN
DECLARE credit tinyint;
DECLARE id2 int;
SELECT pankkikortti.credit FROM pankkikortti WHERE pankkikortti.korttinumero = id1 INTO credit;
SELECT pankkikortti.tilinumero FROM pankkikortti WHERE pankkikortti.korttinumero = id1 INTO id2;
IF (credit = 1) THEN SELECT pankkitili.saldo, pankkitili.creditsaldo FROM pankkitili WHERE pankkitili.tilinumero = id2;
ELSE SELECT pankkitili.saldo FROM pankkitili WHERE pankkitili.tilinumero = id2; 
END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `talletus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `talletus`(IN id1 INT, IN summa DOUBLE)
BEGIN
  DECLARE test1 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=id1;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'talletus', summa, id1, '0');
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `tilitapahtuma_katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `tilitapahtuma_katsaus`(
IN id1 INT,
IN alkaenRivilta INT)
BEGIN
	DECLARE id2 INT;
    SELECT tilinumero INTO id2 FROM pankkikortti WHERE korttinumero = id1;
	SELECT * FROM tapahtumat WHERE tilinumero=id2 ORDER BY aikaleima DESC LIMIT alkaenRivilta, 10;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `tili_katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `tili_katsaus`(
IN id1 INT,
OUT omistaja VARCHAR(20),
OUT creditSaldo FLOAT,
OUT debitSaldo FLOAT)
BEGIN
DECLARE credit tinyint;
DECLARE id2 int;
SELECT pankkikortti.credit INTO credit FROM pankkikortti WHERE pankkikortti.korttinumero = id1;
SELECT pankkikortti.tilinumero INTO id2 FROM pankkikortti WHERE pankkikortti.korttinumero = id1;
SELECT nimi INTO omistaja FROM asiakas JOIN asiakas_pankkitili ON asiakas_pankkitili.idasiakas = asiakas.idasiakas JOIN pankkitili ON pankkitili.tilinumero = asiakas_pankkitili.tilinumero WHERE pankkitili.tilinumero = id2;
SELECT pankkitili.saldo INTO debitSaldo FROM pankkitili WHERE pankkitili.tilinumero = id2; 
SELECT pankkitili.creditsaldo INTO creditSaldo FROM pankkitili WHERE pankkitili.tilinumero = id2;
IF (credit = 1) THEN SELECT omistaja, debitSaldo, creditSaldo;
ELSE SELECT omistaja, debitSaldo;
END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-12 15:25:44
