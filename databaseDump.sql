-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: atm
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
  `puhelinnumero` varchar(45) NOT NULL,
  PRIMARY KEY (`idasiakas`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (1,'Simo','Merikosken sillan alla','1234567890'),(3,'Simo','Merikosken sillan alla','1234567890');
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asiakas_pankkitili`
--

DROP TABLE IF EXISTS `asiakas_pankkitili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas_pankkitili` (
  `tilinumero` int NOT NULL,
  `idasiakas` int NOT NULL,
  PRIMARY KEY (`tilinumero`,`idasiakas`),
  KEY `fk_assiakas_pankkitili_asiakas1_idx` (`idasiakas`),
  CONSTRAINT `fk_assiakas_pankkitili_asiakas1` FOREIGN KEY (`idasiakas`) REFERENCES `asiakas` (`idasiakas`),
  CONSTRAINT `fk_assiakas_pankkitili_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas_pankkitili`
--

LOCK TABLES `asiakas_pankkitili` WRITE;
/*!40000 ALTER TABLE `asiakas_pankkitili` DISABLE KEYS */;
INSERT INTO `asiakas_pankkitili` VALUES (1,1),(2,1);
/*!40000 ALTER TABLE `asiakas_pankkitili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pankkikortti`
--

DROP TABLE IF EXISTS `pankkikortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pankkikortti` (
  `korttinumero` int NOT NULL AUTO_INCREMENT,
  `pin` varchar(60) DEFAULT NULL,
  `credit` tinyint NOT NULL,
  `tilinumero` int NOT NULL,
  `pinVaarin` int DEFAULT NULL,
  `idasiakas` int DEFAULT NULL,
  PRIMARY KEY (`korttinumero`,`tilinumero`),
  KEY `fk_pankkikortti_pankkitili1_idx` (`tilinumero`),
  CONSTRAINT `fk_pankkikortti_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkikortti`
--

LOCK TABLES `pankkikortti` WRITE;
/*!40000 ALTER TABLE `pankkikortti` DISABLE KEYS */;
INSERT INTO `pankkikortti` VALUES (4,'$2a$10$t9gCnLquUPWrvn5L/PBiVehWZomUizInOWVHNjooW6yS60vf90g.O',0,1,0,1),(5,'$2a$10$jzdoDp3ey2rfF8JOLYkyLOmNjbyznOpmmn7X7uM3d6o06PiFQ1phG',1,2,1,1),(9,'$2a$10$09dzT5gRRXVS04xImVP1J.4ZLS.q4zwa4OIwTmr5LEvzAhR7bKIhW',0,1,0,1),(10,'$2a$10$HINFG8O.Ecd59McFLHgfgO/VUOK3eJI0O5U12JJNkPriocyrugUDq',0,1,0,1);
/*!40000 ALTER TABLE `pankkikortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pankkitili`
--

DROP TABLE IF EXISTS `pankkitili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pankkitili` (
  `tilinumero` int NOT NULL AUTO_INCREMENT,
  `saldo` double DEFAULT NULL,
  `credit` double DEFAULT NULL,
  PRIMARY KEY (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkitili`
--

LOCK TABLES `pankkitili` WRITE;
/*!40000 ALTER TABLE `pankkitili` DISABLE KEYS */;
INSERT INTO `pankkitili` VALUES (1,12,NULL),(2,NULL,1500);
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
  `korttinumero` int NOT NULL,
  `tilinumero` int NOT NULL,
  `aikaleima` datetime NOT NULL,
  `tapahtuma` varchar(45) NOT NULL,
  `summa` double DEFAULT NULL,
  `credit` tinyint NOT NULL,
  PRIMARY KEY (`idtapahtumat`),
  KEY `fk_tapahtumat_pankkitili_idx` (`tilinumero`),
  CONSTRAINT `fk_tapahtumat_pankkitili` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tapahtumat`
--

LOCK TABLES `tapahtumat` WRITE;
/*!40000 ALTER TABLE `tapahtumat` DISABLE KEYS */;
INSERT INTO `tapahtumat` VALUES (1,1,1,'2058-01-19 03:14:07','Automaattinosto',-80,0),(2,5,2,'2021-12-01 19:25:02','Automaattinosto',2,0),(3,5,2,'2021-12-01 19:26:06','Automaattinosto',25,0),(4,5,2,'2021-12-01 19:26:50','Automaattinosto',5,0),(5,5,2,'2021-12-01 19:27:36','Automaattinosto',0,0),(6,5,2,'2021-12-01 19:35:27','Automaattinosto',10,0),(7,5,2,'2021-12-01 19:36:55','Automaattinosto',10,0),(8,5,2,'2021-12-01 19:44:07','Automaattitalletus',500,0),(9,5,2,'2021-12-01 19:51:32','Automaattinosto',-100,0),(10,5,2,'2021-12-01 19:52:34','Automaattitalletus',5,0),(11,5,2,'2021-12-01 20:32:14','Automaattinosto',-100,0),(12,5,2,'2021-12-01 20:35:05','Automaattitalletus',NULL,0),(13,5,2,'2021-12-01 20:35:44','Automaattinosto',-5,0);
/*!40000 ALTER TABLE `tapahtumat` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-02 14:32:35
