--
-- PostgreSQL database dump
--

-- Dumped from database version 13.1
-- Dumped by pg_dump version 13.1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: pseudo_encrypt(bigint); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.pseudo_encrypt(value bigint) RETURNS bigint
    LANGUAGE plpgsql IMMUTABLE STRICT
    AS $$
DECLARE
l1 bigint;
l2 bigint;
r1 bigint;
r2 bigint;
i int:=0;
BEGIN
    l1:= (VALUE >> 32) & 4294967295::bigint;
    r1:= VALUE & 4294967295;
    WHILE i < 3 LOOP
        l2 := r1;
        r2 := l1 # ((((1366.0 * r1 + 150889) % 714025) / 714025.0) * 32767*32767)::int;
        l1 := l2;
        r1 := r2;
        i := i + 1;
    END LOOP;
RETURN ((l1::bigint << 32) + r1);
END;
$$;


ALTER FUNCTION public.pseudo_encrypt(value bigint) OWNER TO postgres;

--
-- Name: random_between(bigint, bigint); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.random_between(low bigint, high bigint) RETURNS bigint
    LANGUAGE plpgsql STRICT
    AS $$
BEGIN
   RETURN floor(random()* (high-low + 1) + low);
END;
$$;


ALTER FUNCTION public.random_between(low bigint, high bigint) OWNER TO postgres;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: categories; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.categories (
    id bigint NOT NULL,
    name text NOT NULL
);


ALTER TABLE public.categories OWNER TO postgres;

--
-- Name: categories_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.categories ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.categories_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: countries; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.countries (
    id integer NOT NULL,
    country_code text NOT NULL,
    country_name text NOT NULL
);


ALTER TABLE public.countries OWNER TO postgres;

--
-- Name: countries_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.countries ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.countries_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: products; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.products (
    id bigint NOT NULL,
    name text NOT NULL,
    description text,
    price integer NOT NULL,
    stock integer NOT NULL,
    category integer,
    image text,
    created date NOT NULL,
    last_updated date NOT NULL,
    CONSTRAINT products_stock_check CHECK ((stock >= 0))
);


ALTER TABLE public.products OWNER TO postgres;

--
-- Name: products_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.products ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.products_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: reviews; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.reviews (
    id integer NOT NULL,
    stars integer NOT NULL,
    review text NOT NULL,
    author bigint NOT NULL,
    created date NOT NULL,
    product integer NOT NULL,
    last_updated date NOT NULL,
    CONSTRAINT reviews_stars_check CHECK ((stars > 0)),
    CONSTRAINT reviews_stars_check1 CHECK ((stars <= 5))
);


ALTER TABLE public.reviews OWNER TO postgres;

--
-- Name: reviews_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.reviews ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.reviews_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id bigint DEFAULT public.random_between((1)::bigint, '999999999999999999'::bigint) NOT NULL,
    username text NOT NULL,
    birthday date,
    country integer,
    registered timestamp with time zone NOT NULL,
    password text NOT NULL,
    profile_picture text,
    isadmin boolean
);


ALTER TABLE public.users OWNER TO postgres;

--
-- Name: COLUMN users.password; Type: COMMENT; Schema: public; Owner: postgres
--

COMMENT ON COLUMN public.users.password IS 'bcrypt password hash';


--
-- Data for Name: categories; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.categories (id, name) FROM stdin;
1	Toys
2	Laptops
3	Cars
4	Desktops
5	Alchohol
6	Electronics
7	Animals
\.


--
-- Data for Name: countries; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.countries (id, country_code, country_name) FROM stdin;
1	AF	Afghanistan
2	AX	Åland Islands
3	AL	Albania
4	DZ	Algeria
5	AS	American Samoa
6	AD	Andorra
7	AO	Angola
8	AI	Anguilla
9	AQ	Antarctica
10	AG	Antigua & Barbuda
11	AR	Argentina
12	AM	Armenia
13	AW	Aruba
14	AU	Australia
15	AT	Austria
16	AZ	Azerbaijan
17	BS	Bahamas
18	BH	Bahrain
19	BD	Bangladesh
20	BB	Barbados
21	BY	Belarus
22	BE	Belgium
23	BZ	Belize
24	BJ	Benin
25	BM	Bermuda
26	BT	Bhutan
27	BO	Bolivia
28	BA	Bosnia & Herzegovina
29	BW	Botswana
30	BV	Bouvet Island
31	BR	Brazil
32	IO	British Indian Ocean Territory
33	VG	British Virgin Islands
34	BN	Brunei
35	BG	Bulgaria
36	BF	Burkina Faso
37	BI	Burundi
38	KH	Cambodia
39	CM	Cameroon
40	CA	Canada
41	CV	Cape Verde
42	BQ	Caribbean Netherlands
43	KY	Cayman Islands
44	CF	Central African Republic
45	TD	Chad
46	CL	Chile
47	CN	China
48	CX	Christmas Island
49	CC	Cocos (Keeling) Islands
50	CO	Colombia
51	KM	Comoros
52	CG	Congo - Brazzaville
53	CD	Congo - Kinshasa
54	CK	Cook Islands
55	CR	Costa Rica
56	CI	Côte d’Ivoire
57	HR	Croatia
58	CU	Cuba
59	CW	Curaçao
60	CY	Cyprus
61	CZ	Czechia
62	DK	Denmark
63	DJ	Djibouti
64	DM	Dominica
65	DO	Dominican Republic
66	EC	Ecuador
67	EG	Egypt
68	SV	El Salvador
69	GQ	Equatorial Guinea
70	ER	Eritrea
71	EE	Estonia
72	SZ	Eswatini
73	ET	Ethiopia
74	FK	Falkland Islands
75	FO	Faroe Islands
76	FJ	Fiji
77	FI	Finland
78	FR	France
79	GF	French Guiana
80	PF	French Polynesia
81	TF	French Southern Territories
82	GA	Gabon
83	GM	Gambia
84	GE	Georgia
85	DE	Germany
86	GH	Ghana
87	GI	Gibraltar
88	GR	Greece
89	GL	Greenland
90	GD	Grenada
91	GP	Guadeloupe
92	GU	Guam
93	GT	Guatemala
94	GG	Guernsey
95	GN	Guinea
96	GW	Guinea-Bissau
97	GY	Guyana
98	HT	Haiti
99	HM	Heard & McDonald Islands
100	HN	Honduras
101	HK	Hong Kong SAR China
102	HU	Hungary
103	IS	Iceland
104	IN	India
105	ID	Indonesia
106	IR	Iran
107	IQ	Iraq
108	IE	Ireland
109	IM	Isle of Man
110	IL	Israel
111	IT	Italy
112	JM	Jamaica
113	JP	Japan
114	JE	Jersey
115	JO	Jordan
116	KZ	Kazakhstan
117	KE	Kenya
118	KI	Kiribati
119	KW	Kuwait
120	KG	Kyrgyzstan
121	LA	Laos
122	LV	Latvia
123	LB	Lebanon
124	LS	Lesotho
125	LR	Liberia
126	LY	Libya
127	LI	Liechtenstein
128	LT	Lithuania
129	LU	Luxembourg
130	MO	Macao SAR China
131	MG	Madagascar
132	MW	Malawi
133	MY	Malaysia
134	MV	Maldives
135	ML	Mali
136	MT	Malta
137	MH	Marshall Islands
138	MQ	Martinique
139	MR	Mauritania
140	MU	Mauritius
141	YT	Mayotte
142	MX	Mexico
143	FM	Micronesia
144	MD	Moldova
145	MC	Monaco
146	MN	Mongolia
147	ME	Montenegro
148	MS	Montserrat
149	MA	Morocco
150	MZ	Mozambique
151	MM	Myanmar (Burma)
152	NA	Namibia
153	NR	Nauru
154	NP	Nepal
155	NL	Netherlands
156	NC	New Caledonia
157	NZ	New Zealand
158	NI	Nicaragua
159	NE	Niger
160	NG	Nigeria
161	NU	Niue
162	NF	Norfolk Island
163	KP	North Korea
164	MK	North Macedonia
165	MP	Northern Mariana Islands
166	NO	Norway
167	OM	Oman
168	PK	Pakistan
169	PW	Palau
170	PS	Palestinian Territories
171	PA	Panama
172	PG	Papua New Guinea
173	PY	Paraguay
174	PE	Peru
175	PH	Philippines
176	PN	Pitcairn Islands
177	PL	Poland
178	PT	Portugal
179	PR	Puerto Rico
180	QA	Qatar
181	RE	Réunion
182	RO	Romania
183	RU	Russia
184	RW	Rwanda
185	WS	Samoa
186	SM	San Marino
187	ST	São Tomé & Príncipe
188	SA	Saudi Arabia
189	SN	Senegal
190	RS	Serbia
191	SC	Seychelles
192	SL	Sierra Leone
193	SG	Singapore
194	SX	Sint Maarten
195	SK	Slovakia
196	SI	Slovenia
197	SB	Solomon Islands
198	SO	Somalia
199	ZA	South Africa
200	GS	South Georgia & South Sandwich Islands
201	KR	South Korea
202	SS	South Sudan
203	ES	Spain
204	LK	Sri Lanka
205	BL	St. Barthélemy
206	SH	St. Helena
207	KN	St. Kitts & Nevis
208	LC	St. Lucia
209	MF	St. Martin
210	PM	St. Pierre & Miquelon
211	VC	St. Vincent & Grenadines
212	SD	Sudan
213	SR	Suriname
214	SJ	Svalbard & Jan Mayen
215	SE	Sweden
216	CH	Switzerland
217	SY	Syria
218	TW	Taiwan
219	TJ	Tajikistan
220	TZ	Tanzania
221	TH	Thailand
222	TL	Timor-Leste
223	TG	Togo
224	TK	Tokelau
225	TO	Tonga
226	TT	Trinidad & Tobago
227	TN	Tunisia
228	TR	Turkey
229	TM	Turkmenistan
230	TC	Turks & Caicos Islands
231	TV	Tuvalu
232	UM	U.S. Outlying Islands
233	VI	U.S. Virgin Islands
234	UG	Uganda
235	UA	Ukraine
236	AE	United Arab Emirates
237	GB	United Kingdom
238	US	United States
239	UY	Uruguay
240	UZ	Uzbekistan
241	VU	Vanuatu
242	VA	Vatican City
243	VE	Venezuela
244	VN	Vietnam
245	WF	Wallis & Futuna
246	EH	Western Sahara
247	YE	Yemen
248	ZM	Zambia
249	ZW	Zimbabwe
\.


--
-- Data for Name: products; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.products (id, name, description, price, stock, category, image, created, last_updated) FROM stdin;
1	Lego	This is a lego	12	2	1	\N	2001-12-31	2002-12-31
2	Apple	This is an apple	2	1	2	\N	2003-12-31	2004-12-31
3	Russian vodka	This is true vodka	2000	9001	5	\N	1993-12-31	2001-12-31
4	Monkey	Cheap endagered monkeys	5	4	7	\N	1993-12-31	2001-12-31
\.


--
-- Data for Name: reviews; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.reviews (id, stars, review, author, created, product, last_updated) FROM stdin;
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.users (id, username, birthday, country, registered, password, profile_picture, isadmin) FROM stdin;
1	12destroyer21	2002-07-05	62	2021-04-06 00:00:00+02	$2a$10$T7S.2oNyXEOP4d5GpIMatebARCiwG00ZhXGneg8vTHEkfdBL625Fy	\N	t
123	dannythehacker	2002-01-01	183	2021-04-20 00:00:00+02	$2y$12$y00XpUwSHA7qrrRo7Xy8l.CNwgbabkJT1P8e0D66VuY0HzLANoW8u	\N	f
\.


--
-- Name: categories_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.categories_id_seq', 1, false);


--
-- Name: countries_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.countries_id_seq', 249, true);


--
-- Name: products_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.products_id_seq', 1, false);


--
-- Name: reviews_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.reviews_id_seq', 1, false);


--
-- Name: categories categories_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.categories
    ADD CONSTRAINT categories_pkey PRIMARY KEY (id);


--
-- Name: countries countries_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.countries
    ADD CONSTRAINT countries_pkey PRIMARY KEY (id);


--
-- Name: products products_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.products
    ADD CONSTRAINT products_pkey PRIMARY KEY (id);


--
-- Name: reviews reviews_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reviews
    ADD CONSTRAINT reviews_pkey PRIMARY KEY (id);


--
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- Name: users users_username_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_username_key UNIQUE (username);


--
-- Name: products fk_category; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.products
    ADD CONSTRAINT fk_category FOREIGN KEY (category) REFERENCES public.categories(id);


--
-- Name: reviews fk_product; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reviews
    ADD CONSTRAINT fk_product FOREIGN KEY (product) REFERENCES public.products(id);


--
-- Name: reviews reviews_author_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.reviews
    ADD CONSTRAINT reviews_author_fkey FOREIGN KEY (author) REFERENCES public.users(id);


--
-- PostgreSQL database dump complete
--

