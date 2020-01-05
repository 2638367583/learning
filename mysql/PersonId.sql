CREATE TABLE IF NOT EXISTS address (
    AddressId INT AUTO_INCREMENT,
    PersonId INT,
    City VARCHAR(20),
    State VARCHAR(20),
    PRIMARY KEY(AddressId)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS persion (
    PersonId INT AUTO_INCREMENT,
    PRIMARY KEY(PersonId),
    FirstName VARCHAR(20) NOT NULL,
    LastName VARCHAR(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO persion 
(PersonId, FirstName, LastName)
VALUES 
(1, "李", "雷雨");

INSERT INTO address
(AddressId, PersonId, City, State)
VALUES
(1, 1, "遵义", "中国");
