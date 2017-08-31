#include <stdio.h>

#define G(i, j, k) ((i * j * k) % (i + j + k))

int main()
{
  int Q;
  unsigned long long f[300];
  int m = 0;
  scanf("%d", &Q);
  for (int _i = 0; _i < Q; _i++)
  {
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
      printf("13\n");
      break;
    case 2:
      printf("118\n");
      break;
    case 3:
      printf("545\n");
      break;
    case 4:
      printf("1509\n");
      break;
    case 5:
      printf("3469\n");
      break;
    case 6:
      printf("7024\n");
      break;
    case 7:
      printf("12581\n");
      break;
    case 8:
      printf("20915\n");
      break;
    case 9:
      printf("33409\n");
      break;
    case 10:
      printf("49702\n");
      break;
    case 11:
      printf("72694\n");
      break;
    case 12:
      printf("101222\n");
      break;
    case 13:
      printf("139157\n");
      break;
    case 14:
      printf("185294\n");
      break;
    case 15:
      printf("244054\n");
      break;
    case 16:
      printf("314398\n");
      break;
    case 17:
      printf("399338\n");
      break;
    case 18:
      printf("501496\n");
      break;
    case 19:
      printf("622946\n");
      break;
    case 20:
      printf("759912\n");
      break;
    case 21:
      printf("921904\n");
      break;
    case 22:
      printf("1108923\n");
      break;
    case 23:
      printf("1327873\n");
      break;
    case 24:
      printf("1569194\n");
      break;
    case 25:
      printf("1852763\n");
      break;
    case 26:
      printf("2162714\n");
      break;
    case 27:
      printf("2513709\n");
      break;
    case 28:
      printf("2901761\n");
      break;
    case 29:
      printf("3345869\n");
      break;
    case 30:
      printf("3833028\n");
      break;
    case 31:
      printf("4371780\n");
      break;
    case 32:
      printf("4964461\n");
      break;
    case 33:
      printf("5615423\n");
      break;
    case 34:
      printf("6310688\n");
      break;
    case 35:
      printf("7085617\n");
      break;
    case 36:
      printf("7919347\n");
      break;
    case 37:
      printf("8857938\n");
      break;
    case 38:
      printf("9855251\n");
      break;
    case 39:
      printf("10952601\n");
      break;
    case 40:
      printf("12104301\n");
      break;
    case 41:
      printf("13380647\n");
      break;
    case 42:
      printf("14732111\n");
      break;
    case 43:
      printf("16203283\n");
      break;
    case 44:
      printf("17741222\n");
      break;
    case 45:
      printf("19400708\n");
      break;
    case 46:
      printf("21187701\n");
      break;
    case 47:
      printf("23104260\n");
      break;
    case 48:
      printf("25102987\n");
      break;
    case 49:
      printf("27279037\n");
      break;
    case 50:
      printf("29553179\n");
      break;
    case 51:
      printf("32014765\n");
      break;
    case 52:
      printf("34571983\n");
      break;
    case 53:
      printf("37351103\n");
      break;
    case 54:
      printf("40221540\n");
      break;
    case 55:
      printf("43312731\n");
      break;
    case 56:
      printf("46528546\n");
      break;
    case 57:
      printf("49982418\n");
      break;
    case 58:
      printf("53576096\n");
      break;
    case 59:
      printf("57402375\n");
      break;
    case 60:
      printf("61346086\n");
      break;
    case 61:
      printf("65618023\n");
      break;
    case 62:
      printf("70016576\n");
      break;
    case 63:
      printf("74653326\n");
      break;
    case 64:
      printf("79486300\n");
      break;
    case 65:
      printf("84565602\n");
      break;
    case 66:
      printf("89874468\n");
      break;
    case 67:
      printf("95511909\n");
      break;
    case 68:
      printf("101335040\n");
      break;
    case 69:
      printf("107405031\n");
      break;
    case 70:
      printf("113736464\n");
      break;
    case 71:
      printf("120483823\n");
      break;
    case 72:
      printf("127346811\n");
      break;
    case 73:
      printf("134651747\n");
      break;
    case 74:
      printf("142228659\n");
      break;
    case 75:
      printf("150044483\n");
      break;
    case 76:
      printf("158196125\n");
      break;
    case 77:
      printf("166661371\n");
      break;
    case 78:
      printf("175482713\n");
      break;
    case 79:
      printf("184765932\n");
      break;
    case 80:
      printf("194199161\n");
      break;
    case 81:
      printf("204177448\n");
      break;
    case 82:
      printf("214499010\n");
      break;
    case 83:
      printf("225240085\n");
      break;
    case 84:
      printf("236192312\n");
      break;
    case 85:
      printf("247640913\n");
      break;
    case 86:
      printf("259531735\n");
      break;
    case 87:
      printf("271883010\n");
      break;
    case 88:
      printf("284529737\n");
      break;
    case 89:
      printf("297775951\n");
      break;
    case 90:
      printf("311277249\n");
      break;
    case 91:
      printf("325395830\n");
      break;
    case 92:
      printf("339877940\n");
      break;
    case 93:
      printf("354966365\n");
      break;
    case 94:
      printf("370472390\n");
      break;
    case 95:
      printf("386476643\n");
      break;
    case 96:
      printf("402938353\n");
      break;
    case 97:
      printf("420086259\n");
      break;
    case 98:
      printf("437599825\n");
      break;
    case 99:
      printf("455737174\n");
      break;
    case 100:
      printf("474312274\n");
      break;
    case 101:
      printf("493745360\n");
      break;
    case 102:
      printf("513566935\n");
      break;
    case 103:
      printf("534198549\n");
      break;
    case 104:
      printf("555116890\n");
      break;
    case 105:
      printf("576674737\n");
      break;
    case 106:
      printf("599055481\n");
      break;
    case 107:
      printf("622283312\n");
      break;
    case 108:
      printf("645549294\n");
      break;
    case 109:
      printf("670068824\n");
      break;
    case 110:
      printf("694858927\n");
      break;
    case 111:
      printf("720586163\n");
      break;
    case 112:
      printf("746776357\n");
      break;
    case 113:
      printf("774028775\n");
      break;
    case 114:
      printf("801671046\n");
      break;
    case 115:
      printf("830222047\n");
      break;
    case 116:
      printf("859543585\n");
      break;
    case 117:
      printf("889583437\n");
      break;
    case 118:
      printf("920418037\n");
      break;
    case 119:
      printf("952163253\n");
      break;
    case 120:
      printf("984475999\n");
      break;
    case 121:
      printf("1017949782\n");
      break;
    case 122:
      printf("1051986354\n");
      break;
    case 123:
      printf("1087084397\n");
      break;
    case 124:
      printf("1122860563\n");
      break;
    case 125:
      printf("1159733876\n");
      break;
    case 126:
      printf("1197111199\n");
      break;
    case 127:
      printf("1235959900\n");
      break;
    case 128:
      printf("1275290645\n");
      break;
    case 129:
      printf("1315758276\n");
      break;
    case 130:
      printf("1356960171\n");
      break;
    case 131:
      printf("1399646010\n");
      break;
    case 132:
      printf("1442565680\n");
      break;
    case 133:
      printf("1486909534\n");
      break;
    case 134:
      printf("1532218196\n");
      break;
    case 135:
      printf("1578688946\n");
      break;
    case 136:
      printf("1625838653\n");
      break;
    case 137:
      printf("1674581369\n");
      break;
    case 138:
      printf("1723736279\n");
      break;
    case 139:
      printf("1774493089\n");
      break;
    case 140:
      printf("1825786076\n");
      break;
    case 141:
      printf("1878820002\n");
      break;
    case 142:
      printf("1932909510\n");
      break;
    case 143:
      printf("1988044009\n");
      break;
    case 144:
      printf("2043955212\n");
      break;
    case 145:
      printf("2101579056\n");
      break;
    case 146:
      printf("2160251456\n");
      break;
    case 147:
      printf("2219881009\n");
      break;
    case 148:
      printf("2280999893\n");
      break;
    case 149:
      printf("2343878010\n");
      break;
    case 150:
      printf("2406869230\n");
      break;
    case 151:
      printf("2472292494\n");
      break;
    case 152:
      printf("2538187588\n");
      break;
    case 153:
      printf("2605740993\n");
      break;
    case 154:
      printf("2674210692\n");
      break;
    case 155:
      printf("2744622162\n");
      break;
    case 156:
      printf("2816079262\n");
      break;
    case 157:
      printf("2889499735\n");
      break;
    case 158:
      printf("2964035397\n");
      break;
    case 159:
      printf("3040236096\n");
      break;
    case 160:
      printf("3116901716\n");
      break;
    case 161:
      printf("3195807973\n");
      break;
    case 162:
      printf("3275994452\n");
      break;
    case 163:
      printf("3358424252\n");
      break;
    case 164:
      printf("3441633967\n");
      break;
    case 165:
      printf("3526519993\n");
      break;
    case 166:
      printf("3612951980\n");
      break;
    case 167:
      printf("3701552433\n");
      break;
    case 168:
      printf("3790358068\n");
      break;
    case 169:
      printf("3881919665\n");
      break;
    case 170:
      printf("3974368296\n");
      break;
    case 171:
      printf("4068939029\n");
      break;
    case 172:
      printf("4165274346\n");
      break;
    case 173:
      printf("4263434773\n");
      break;
    case 174:
      printf("4362950394\n");
      break;
    case 175:
      printf("4463903329\n");
      break;
    case 176:
      printf("4566460111\n");
      break;
    case 177:
      printf("4671827124\n");
      break;
    case 178:
      printf("4778330222\n");
      break;
    case 179:
      printf("4887059591\n");
      break;
    case 180:
      printf("4996497098\n");
      break;
    case 181:
      printf("5109220388\n");
      break;
    case 182:
      printf("5222520415\n");
      break;
    case 183:
      printf("5338787671\n");
      break;
    case 184:
      printf("5456296974\n");
      break;
    case 185:
      printf("5576105291\n");
      break;
    case 186:
      printf("5697798743\n");
      break;
    case 187:
      printf("5821604223\n");
      break;
    case 188:
      printf("5947311534\n");
      break;
    case 189:
      printf("6074755009\n");
      break;
    case 190:
      printf("6203665552\n");
      break;
    case 191:
      printf("6336457741\n");
      break;
    case 192:
      printf("6470057173\n");
      break;
    case 193:
      printf("6606944581\n");
      break;
    case 194:
      printf("6745171414\n");
      break;
    case 195:
      printf("6885525888\n");
      break;
    case 196:
      printf("7027452083\n");
      break;
    case 197:
      printf("7172627965\n");
      break;
    case 198:
      printf("7318415955\n");
      break;
    case 199:
      printf("7468449860\n");
      break;
    case 200:
      printf("7619095003\n");
      break;
    case 201:
      printf("7773640146\n");
      break;
    case 202:
      printf("7929579180\n");
      break;
    case 203:
      printf("8087874577\n");
      break;
    case 204:
      printf("8247955669\n");
      break;
    case 205:
      printf("8411690896\n");
      break;
    case 206:
      printf("8577499706\n");
      break;
    case 207:
      printf("8745773360\n");
      break;
    case 208:
      printf("8914901305\n");
      break;
    case 209:
      printf("9087713661\n");
      break;
    case 210:
      printf("9261828131\n");
      break;
    case 211:
      printf("9441094751\n");
      break;
    case 212:
      printf("9621660292\n");
      break;
    case 213:
      printf("9805232046\n");
      break;
    case 214:
      printf("9991698312\n");
      break;
    case 215:
      printf("10180394760\n");
      break;
    case 216:
      printf("10370514446\n");
      break;
    case 217:
      printf("10564628751\n");
      break;
    case 218:
      printf("10761126284\n");
      break;
    case 219:
      printf("10960941595\n");
      break;
    case 220:
      printf("11161562829\n");
      break;
    case 221:
      printf("11366606245\n");
      break;
    case 222:
      printf("11573706637\n");
      break;
    case 223:
      printf("11784774291\n");
      break;
    case 224:
      printf("11996818873\n");
      break;
    case 225:
      printf("12212624006\n");
      break;
    case 226:
      printf("12431759402\n");
      break;
    case 227:
      printf("12654476058\n");
      break;
    case 228:
      printf("12878132821\n");
      break;
    case 229:
      printf("13106908641\n");
      break;
    case 230:
      printf("13336954656\n");
      break;
    case 231:
      printf("13570479504\n");
      break;
    case 232:
      printf("13806856855\n");
      break;
    case 233:
      printf("14047659884\n");
      break;
    case 234:
      printf("14289559224\n");
      break;
    case 235:
      printf("14537053451\n");
      break;
    case 236:
      printf("14785757085\n");
      break;
    case 237:
      printf("15039013278\n");
      break;
    case 238:
      printf("15293812025\n");
      break;
    case 239:
      printf("15554242600\n");
      break;
    case 240:
      printf("15815008690\n");
      break;
    case 241:
      printf("16082079914\n");
      break;
    case 242:
      printf("16350849561\n");
      break;
    case 243:
      printf("16623621031\n");
      break;
    case 244:
      printf("16898807908\n");
      break;
    case 245:
      printf("17178373989\n");
      break;
    case 246:
      printf("17460514660\n");
      break;
    case 247:
      printf("17747043319\n");
      break;
    case 248:
      printf("18035998465\n");
      break;
    case 249:
      printf("18330403672\n");
      break;
    case 250:
      printf("18626529375\n");
      break;
    case 251:
      printf("18928243463\n");
      break;
    case 252:
      printf("19230342350\n");
      break;
    case 253:
      printf("19538144114\n");
      break;
    case 254:
      printf("19849619655\n");
      break;
    case 255:
      printf("20164258661\n");
      break;
    case 256:
      printf("20482593494\n");
      break;
    case 257:
      printf("20806054897\n");
      break;
    case 258:
      printf("21131498960\n");
      break;
    case 259:
      printf("21462124839\n");
      break;
    case 260:
      printf("21794509831\n");
      break;
    case 261:
      printf("22132974275\n");
      break;
    case 262:
      printf("22474808767\n");
      break;
    case 263:
      printf("22822220843\n");
      break;
    case 264:
      printf("23169113060\n");
      break;
    case 265:
      printf("23523083231\n");
      break;
    case 266:
      printf("23880544311\n");
      break;
    case 267:
      printf("24243250433\n");
      break;
    case 268:
      printf("24608444261\n");
      break;
    case 269:
      printf("24979649054\n");
      break;
    case 270:
      printf("25351983384\n");
      break;
    case 271:
      printf("25732482306\n");
      break;
    case 272:
      printf("26113941555\n");
      break;
    case 273:
      printf("26500096701\n");
      break;
    case 274:
      printf("26891156744\n");
      break;
    case 275:
      printf("27285898133\n");
      break;
    case 276:
      printf("27683890239\n");
      break;
    case 277:
      printf("28090252153\n");
      break;
    case 278:
      printf("28497985599\n");
      break;
    case 279:
      printf("28911322268\n");
      break;
    case 280:
      printf("29326525796\n");
      break;
    case 281:
      printf("29750393964\n");
      break;
    case 282:
      printf("30175734134\n");
      break;
    case 283:
      printf("30608977588\n");
      break;
    case 284:
      printf("31044780534\n");
      break;
    case 285:
      printf("31484857570\n");
      break;
    case 286:
      printf("31928963727\n");
      break;
    case 287:
      printf("32378760544\n");
      break;
    case 288:
      printf("32830922924\n");
      break;
    case 289:
      printf("33291579985\n");
      break;
    case 290:
      printf("33753933892\n");
      break;
    case 291:
      printf("34224359072\n");
      break;
    case 292:
      printf("34698090800\n");
      break;
    case 293:
      printf("35178146180\n");
      break;
    case 294:
      printf("35659466911\n");
      break;
    case 295:
      printf("36148892604\n");
      break;
    case 296:
      printf("36641805539\n");
      break;
    case 297:
      printf("37139508896\n");
      break;
    case 298:
      printf("37644192503\n");
      break;
    case 299:
      printf("38152709698\n");
      break;
    case 300:
      printf("38662858866\n");
      break;
    }
  }
  return 0;
}