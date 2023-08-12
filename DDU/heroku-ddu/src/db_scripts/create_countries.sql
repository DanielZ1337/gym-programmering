DROP TABLE IF EXISTS "countries";
CREATE TABLE "countries"(
    "id" INT GENERATED ALWAYS AS IDENTITY,
    "country_code" TEXT NOT NULL,
    "country_name" TEXT NOT NULL,
    PRIMARY KEY (id)
);

INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AF', E'Afghanistan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AX', E'Åland Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AL', E'Albania');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'DZ', E'Algeria');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AS', E'American Samoa');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AD', E'Andorra');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AO', E'Angola');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AI', E'Anguilla');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AQ', E'Antarctica');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AG', E'Antigua & Barbuda');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AR', E'Argentina');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AM', E'Armenia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AW', E'Aruba');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AU', E'Australia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AT', E'Austria');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AZ', E'Azerbaijan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BS', E'Bahamas');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BH', E'Bahrain');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BD', E'Bangladesh');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BB', E'Barbados');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BY', E'Belarus');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BE', E'Belgium');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BZ', E'Belize');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BJ', E'Benin');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BM', E'Bermuda');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BT', E'Bhutan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BO', E'Bolivia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BA', E'Bosnia & Herzegovina');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BW', E'Botswana');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BV', E'Bouvet Island');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BR', E'Brazil');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'IO', E'British Indian Ocean Territory');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'VG', E'British Virgin Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BN', E'Brunei');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BG', E'Bulgaria');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BF', E'Burkina Faso');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BI', E'Burundi');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'KH', E'Cambodia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CM', E'Cameroon');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CA', E'Canada');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CV', E'Cape Verde');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BQ', E'Caribbean Netherlands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'KY', E'Cayman Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CF', E'Central African Republic');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TD', E'Chad');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CL', E'Chile');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CN', E'China');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CX', E'Christmas Island');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CC', E'Cocos (Keeling) Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CO', E'Colombia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'KM', E'Comoros');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CG', E'Congo - Brazzaville');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CD', E'Congo - Kinshasa');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CK', E'Cook Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CR', E'Costa Rica');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CI', E'Côte d’Ivoire');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'HR', E'Croatia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CU', E'Cuba');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CW', E'Curaçao');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CY', E'Cyprus');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CZ', E'Czechia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'DK', E'Denmark');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'DJ', E'Djibouti');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'DM', E'Dominica');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'DO', E'Dominican Republic');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'EC', E'Ecuador');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'EG', E'Egypt');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SV', E'El Salvador');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GQ', E'Equatorial Guinea');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'ER', E'Eritrea');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'EE', E'Estonia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SZ', E'Eswatini');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'ET', E'Ethiopia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'FK', E'Falkland Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'FO', E'Faroe Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'FJ', E'Fiji');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'FI', E'Finland');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'FR', E'France');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GF', E'French Guiana');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PF', E'French Polynesia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TF', E'French Southern Territories');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GA', E'Gabon');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GM', E'Gambia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GE', E'Georgia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'DE', E'Germany');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GH', E'Ghana');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GI', E'Gibraltar');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GR', E'Greece');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GL', E'Greenland');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GD', E'Grenada');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GP', E'Guadeloupe');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GU', E'Guam');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GT', E'Guatemala');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GG', E'Guernsey');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GN', E'Guinea');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GW', E'Guinea-Bissau');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GY', E'Guyana');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'HT', E'Haiti');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'HM', E'Heard & McDonald Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'HN', E'Honduras');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'HK', E'Hong Kong SAR China');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'HU', E'Hungary');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'IS', E'Iceland');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'IN', E'India');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'ID', E'Indonesia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'IR', E'Iran');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'IQ', E'Iraq');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'IE', E'Ireland');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'IM', E'Isle of Man');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'IL', E'Israel');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'IT', E'Italy');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'JM', E'Jamaica');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'JP', E'Japan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'JE', E'Jersey');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'JO', E'Jordan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'KZ', E'Kazakhstan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'KE', E'Kenya');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'KI', E'Kiribati');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'KW', E'Kuwait');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'KG', E'Kyrgyzstan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'LA', E'Laos');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'LV', E'Latvia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'LB', E'Lebanon');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'LS', E'Lesotho');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'LR', E'Liberia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'LY', E'Libya');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'LI', E'Liechtenstein');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'LT', E'Lithuania');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'LU', E'Luxembourg');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MO', E'Macao SAR China');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MG', E'Madagascar');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MW', E'Malawi');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MY', E'Malaysia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MV', E'Maldives');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'ML', E'Mali');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MT', E'Malta');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MH', E'Marshall Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MQ', E'Martinique');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MR', E'Mauritania');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MU', E'Mauritius');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'YT', E'Mayotte');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MX', E'Mexico');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'FM', E'Micronesia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MD', E'Moldova');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MC', E'Monaco');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MN', E'Mongolia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'ME', E'Montenegro');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MS', E'Montserrat');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MA', E'Morocco');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MZ', E'Mozambique');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MM', E'Myanmar (Burma)');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NA', E'Namibia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NR', E'Nauru');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NP', E'Nepal');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NL', E'Netherlands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NC', E'New Caledonia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NZ', E'New Zealand');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NI', E'Nicaragua');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NE', E'Niger');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NG', E'Nigeria');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NU', E'Niue');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NF', E'Norfolk Island');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'KP', E'North Korea');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MK', E'North Macedonia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MP', E'Northern Mariana Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'NO', E'Norway');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'OM', E'Oman');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PK', E'Pakistan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PW', E'Palau');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PS', E'Palestinian Territories');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PA', E'Panama');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PG', E'Papua New Guinea');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PY', E'Paraguay');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PE', E'Peru');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PH', E'Philippines');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PN', E'Pitcairn Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PL', E'Poland');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PT', E'Portugal');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PR', E'Puerto Rico');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'QA', E'Qatar');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'RE', E'Réunion');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'RO', E'Romania');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'RU', E'Russia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'RW', E'Rwanda');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'WS', E'Samoa');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SM', E'San Marino');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'ST', E'São Tomé & Príncipe');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SA', E'Saudi Arabia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SN', E'Senegal');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'RS', E'Serbia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SC', E'Seychelles');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SL', E'Sierra Leone');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SG', E'Singapore');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SX', E'Sint Maarten');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SK', E'Slovakia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SI', E'Slovenia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SB', E'Solomon Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SO', E'Somalia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'ZA', E'South Africa');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GS', E'South Georgia & South Sandwich Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'KR', E'South Korea');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SS', E'South Sudan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'ES', E'Spain');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'LK', E'Sri Lanka');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'BL', E'St. Barthélemy');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SH', E'St. Helena');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'KN', E'St. Kitts & Nevis');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'LC', E'St. Lucia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'MF', E'St. Martin');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'PM', E'St. Pierre & Miquelon');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'VC', E'St. Vincent & Grenadines');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SD', E'Sudan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SR', E'Suriname');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SJ', E'Svalbard & Jan Mayen');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SE', E'Sweden');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'CH', E'Switzerland');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'SY', E'Syria');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TW', E'Taiwan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TJ', E'Tajikistan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TZ', E'Tanzania');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TH', E'Thailand');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TL', E'Timor-Leste');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TG', E'Togo');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TK', E'Tokelau');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TO', E'Tonga');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TT', E'Trinidad & Tobago');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TN', E'Tunisia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TR', E'Turkey');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TM', E'Turkmenistan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TC', E'Turks & Caicos Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'TV', E'Tuvalu');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'UM', E'U.S. Outlying Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'VI', E'U.S. Virgin Islands');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'UG', E'Uganda');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'UA', E'Ukraine');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'AE', E'United Arab Emirates');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'GB', E'United Kingdom');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'US', E'United States');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'UY', E'Uruguay');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'UZ', E'Uzbekistan');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'VU', E'Vanuatu');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'VA', E'Vatican City');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'VE', E'Venezuela');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'VN', E'Vietnam');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'WF', E'Wallis & Futuna');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'EH', E'Western Sahara');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'YE', E'Yemen');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'ZM', E'Zambia');
INSERT INTO "countries" ("country_code", "country_name") VALUES (E'ZW', E'Zimbabwe');